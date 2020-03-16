//
// Created by ali-masa on 2/29/20.
//

#include <cstdlib>
#include "dna_manipulation_commands.h"
#include "../dna_data_holder.h"

using namespace std;

Command &DNAManipulationCommand::putArgs(vector<string> &args)
{
    m_args = &args;
    return *this;
}

string SliceCommand::execute()
{
    *m_dnaSeq = m_dnaSeq->slice(m_indexes[0],
            m_indexes[1]);

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
    vector<string>& args = *m_args;
    if(args.size() != s_argsLength)
        //throw an error
        ;
}

void SliceCommand::postStaticParsingParser()
{
    vector<string>& args = *m_args;
    m_indexes.push_back(atoi(args[s_fromIndxArgIndx].c_str()));
    m_indexes.push_back(atoi(args[s_endIndxArgIndx].c_str()));
}

string ReplaceCommand::execute()
{
    DNASequence tmp = *(m_dnaSeq);
    for(vector<pair<size_t,char> >::iterator iter = m_indexToNucleotide.begin();
    iter != m_indexToNucleotide.end(); ++iter)
    {
        size_t index =  iter->first;
        char nucleotide = iter->second;
        // TODO: overload the operator [] to support manipulation
        // tmp[index] = nucleotide;
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
    vector<string>& args = *m_args;
    if(args.size() % 2 != 1)
        //throw an error
        ;
}

void ReplaceCommand::postStaticParsingParser()
{
    vector<string>& args = *m_args;
    for(int i = 0; i < args.size(); ++i)
    {
        size_t index = atoi(args[i].c_str());
        if(args[++i].c_str()[1] != 0)
            //throw an error
            ;
        char nucleotide = args[i].c_str()[0];
        m_indexToNucleotide.push_back(make_pair(index,  nucleotide));
    }
}

string ConcatCommand::execute()
{
    for (size_t i = 0; i < m_dnaSeqToConcat.size(); ++i)
    {
        //TODO: overlaod operator concatination
        //*m_dnaSeq += *m_dnaSeqToConcat[i];
    }
    return __cxx11::string();
}

void ConcatCommand::parseArgs()
{
    ManipulationCommandsParser::parseArgs(*this);
}

void ConcatCommand::preValidator()
{
    vector<string>& args = *m_args;
    if(args.size() > s_atLeastTwoDNASeq)
        //throw an error
        ;
}

void ConcatCommand::postStaticParsingParser()
{
    vector<string>& args = *m_args;
    SharedPointer<DNASequence> sharedDNASequencePntr;
    string identifier;
    for(int i = 0; i < args.size(); ++i)
    {
        identifier =
                args[ManipulationCommandsParser::s_dnaIdentifierArgIndex];
        *sharedDNASequencePntr = ManipulationCommandsParser::
        getDNASeqByIdentifier(identifier);
        m_dnaSeqToConcat.push_back(sharedDNASequencePntr);
    }
}

string PairCommand::execute()
{
    *m_dnaSeq = m_dnaSeq->pairing();
    return __cxx11::string();
}

void PairCommand::parseArgs()
{
    ManipulationCommandsParser::parseArgs(*this);
}

void PairCommand::preValidator()
{
    vector<string>& args = *m_args;
    if(args.size() == 0)
        //throw an error
        ;
}

void PairCommand::postStaticParsingParser() {}

void ManipulationCommandsParser::parseArgs(DNAManipulationCommand &command)
{
    command.preValidator();

    vector<string>& args = *command.m_args;
    string identifier = args[s_dnaIdentifierArgIndex];
    *command.m_dnaSeq =
            ManipulationCommandsParser::getDNASeqByIdentifier(identifier);
    args.erase(args.begin());

    command.postStaticParsingParser();
}

DNASequence &ManipulationCommandsParser::getDNASeqByIdentifier(std::string identifier)
{
    DNASequence* dnaSequence;
    if(identifier[s_dnaIdentifierArgIndex] == s_idIdentifier)
        *dnaSequence = DNADataHolder::getDNASequence(
                atoi(
                        identifier.substr(s_indexAfterIdentifier)
                                .c_str()
                ));
    else
        *dnaSequence = DNADataHolder::getDNASequence(
                identifier.substr(s_indexAfterIdentifier));

    return *dnaSequence;
}
