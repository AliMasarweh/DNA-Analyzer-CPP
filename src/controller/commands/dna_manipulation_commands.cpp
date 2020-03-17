//
// Created by ali-masa on 2/29/20.
//

#include <cstdlib>
#include "dna_manipulation_commands.h"
#include "../dna_data_holder.h"

using namespace std;

Command &DNAManipulationCommand::putArgs(vector<string> &args)
{
    m_args = args;
    return *this;
}

string DNAManipulationCommand::s_sameName("Manipulate this NamedDNASeq");

DNAManipulationCommand::DNAManipulationCommand(): m_newName(s_sameName) {}


void ManipulationCommandsParser::parseArgs(DNAManipulationCommand &command)
{
    command.preValidator();

    // To get the NamedDNASeq by either id or name
    string identifier = command.m_args[s_dnaIdentifierArgIndex];
    *command.m_dnaSeq = DNADataHolder::getDNASeqByIdentifier(identifier);
    command.m_args.erase(command.m_args.begin());

    // To in case this is not working on the same NamedDNASeq
    size_t numOfArgs = command.m_args.size();
    if(command.m_args[numOfArgs-1].find("@") != string::npos)
    {
        if(command.m_args[--numOfArgs] == "@@")
            command.m_newName = "@@";
        else
            command.m_newName = command.m_args[numOfArgs];

        command.m_args.erase(command.m_args.end() - 1);
    }

    command.postStaticParsingParser();

}

string SliceCommand::execute()
{
    *m_namedDnaSequencePntr = *m_dnaSeq;
    if(m_newName != DNAManipulationCommand::s_sameName)
    {
        if(m_newName == "@@")
            m_newName = m_dnaSeq->getName() + "_s1";
        NamedDNASequence tmp(*m_dnaSeq, m_newName);
        m_namedDnaSequencePntr = SharedPointer<NamedDNASequence>(
                new NamedDNASequence(*m_dnaSeq, m_newName));
        DNADataHolder::addDNA(*m_namedDnaSequencePntr);
    }

    m_namedDnaSequencePntr->slice(m_indexes[0], m_indexes[1]);

    // TODO:
    // <Id> <Name> <Seq>
    return __cxx11::string();
}

void SliceCommand::parseArgs()
{
    ManipulationCommandsParser::parseArgs(*this);
}

void SliceCommand::preValidator()
{
    if(m_args.size() != s_argsLength)
        //throw an error
        ;
}

void SliceCommand::postStaticParsingParser()
{
    for (int i = s_fromIndxArgIndx; i <= s_endIndxArgIndx; ++i)
    {
        m_indexes.push_back(atoi(m_args[i].c_str()));
    }
}

string ReplaceCommand::execute()
{
    *m_namedDnaSequencePntr = *m_dnaSeq;

    if(m_newName != DNAManipulationCommand::s_sameName)
    {
        if(m_newName == "@@")
            m_newName = m_dnaSeq->getName() + "_r1";
        m_namedDnaSequencePntr = SharedPointer<NamedDNASequence>(
                new NamedDNASequence(*m_dnaSeq, m_newName));
        DNADataHolder::addDNA(*m_namedDnaSequencePntr);
    }
    for (vector<pair<size_t, char> >::iterator iter = m_indexToNucleotide.begin();
         iter != m_indexToNucleotide.end(); ++iter)
    {
        size_t index = iter->first;
        char nucleotide = iter->second;
        m_namedDnaSequencePntr->replace(index, nucleotide);
    }
    // TODO:
    // <Id> <Name> <Seq>
    return __cxx11::string();
}

void ReplaceCommand::parseArgs()
{
    ManipulationCommandsParser::parseArgs(*this);
}

void ReplaceCommand::preValidator()
{
    if(m_args.size() % 2 != 1)
        //throw an error
        ;
}

void ReplaceCommand::postStaticParsingParser()
{
    for(int i = 0; i < m_args.size(); ++i)
    {
        size_t index = atoi(m_args[i].c_str());
        if(m_args[++i].c_str()[1] != 0)
            //throw an error
            ;
        char nucleotide = m_args[i].c_str()[0];
        m_indexToNucleotide.push_back(make_pair(index,  nucleotide));
    }
}

string ConcatCommand::execute()
{
    *m_namedDnaSequencePntr = *m_dnaSeq;

    if(m_newName != DNAManipulationCommand::s_sameName)
    {
        if(m_newName == "@@")
            m_newName = m_dnaSeq->getName() + "_c1";
        m_namedDnaSequencePntr = SharedPointer<NamedDNASequence>(
                new NamedDNASequence(*m_dnaSeq, m_newName));
        DNADataHolder::addDNA(*m_namedDnaSequencePntr);
    }
    for (size_t i = 0; i < m_dnaSeqToConcat.size(); ++i)
    {
        //TODO: overlaod operator concatination
        m_namedDnaSequencePntr->concat(*m_dnaSeqToConcat[i]);
    }
    return __cxx11::string();
}

void ConcatCommand::parseArgs()
{
    ManipulationCommandsParser::parseArgs(*this);
}

void ConcatCommand::preValidator()
{
    if(m_args.size() > s_atLeastTwoDNASeq)
        //throw an error
        ;
}

void ConcatCommand::postStaticParsingParser()
{
    SharedPointer<NamedDNASequence> sharedDNASequencePntr;
    string identifier;
    for(int i = 0; i < m_args.size(); ++i)
    {
        identifier =
                m_args[ManipulationCommandsParser::s_dnaIdentifierArgIndex];
        *sharedDNASequencePntr = DNADataHolder::getDNASeqByIdentifier(identifier);
        m_dnaSeqToConcat.push_back(sharedDNASequencePntr);
    }
}

string PairCommand::execute()
{
    *m_namedDnaSequencePntr = *m_dnaSeq;

    if(m_newName != DNAManipulationCommand::s_sameName)
    {
        if(m_newName == "@@")
            m_newName = m_dnaSeq->getName() + "_c1";
        m_namedDnaSequencePntr = SharedPointer<NamedDNASequence>(
                new NamedDNASequence(*m_dnaSeq, m_newName));
        DNADataHolder::addDNA(*m_namedDnaSequencePntr);
    }
    m_namedDnaSequencePntr->pairing();
    return __cxx11::string();
}

void PairCommand::parseArgs()
{
    ManipulationCommandsParser::parseArgs(*this);
}

void PairCommand::preValidator()
{
    if(m_args.size() == 0)
        //throw an error
        ;
}

void PairCommand::postStaticParsingParser() {}
