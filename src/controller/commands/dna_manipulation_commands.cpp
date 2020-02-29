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

string SliceCommand::execute() {
    *m_dnaSeq = m_dnaSeq->slice(m_indexes[0],
            m_indexes[1]);

    // TODO:
    // <Id> <Name> <Seq>
    return __cxx11::string();
}

void SliceCommand::parseArgs()
{
    static size_t argsLength = 3,
        fromIndxArgIndx = 1,
        endIndxArgIndx = 2;

    vector<string> args = *m_args;
    if(args.size() != argsLength)
        //throw an error
        ;
    ManipulationCommandsParser::parseArgs(*this);

    m_indexes.push_back(atoi(args[fromIndxArgIndx].c_str()));
    m_indexes.push_back(atoi(args[endIndxArgIndx].c_str()));
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
    vector<string> args = *m_args;
    if(args.size() % 2 != 1)
        //throw an error
        ;
    ManipulationCommandsParser::parseArgs(*this);

    args.erase(args.begin());
    for(int i = 0; i < args.size(); ++i)
    {
        size_t index = atoi(args[i].c_str());
        if(args[++i].c_str()[1] != 0)
            //throw an error
            ;
        char nucleotide = args[++i].c_str()[0];
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
    vector<string> args = *m_args;
    static size_t atLeastTwoDNASeq = 2;
    if(args.size() > atLeastTwoDNASeq)
        //throw an error
        ;
    ManipulationCommandsParser::parseArgs(*this);

    args.erase(args.begin());
    DNASequence* dnaSequencePntr;
    for(int i = 0; i < args.size(); ++i)
    {
        string identifier =
                args[ManipulationCommandsParser::s_dnaIdentifierArgIndex];

        if(identifier[ManipulationCommandsParser::s_dnaIdentifierArgIndex]
            == ManipulationCommandsParser::s_idIdentifier)
            *dnaSequencePntr = DNADataHolder::getDNASequence(
                    atoi( identifier.substr(
                    ManipulationCommandsParser::s_indexAfterIdentifier)
                    .c_str()
                    ));
        else
            *dnaSequencePntr = DNADataHolder::getDNASequence(
                    identifier.substr(
                    ManipulationCommandsParser::s_indexAfterIdentifier));
        SharedPointer<DNASequence> sharedDnaSequencePntr(dnaSequencePntr);
        m_dnaSeqToConcat.push_back(sharedDnaSequencePntr);
    }
}

string PairCommand::execute()
{
    *m_dnaSeq = m_dnaSeq->pairing();
    return __cxx11::string();
}

void PairCommand::parseArgs()
{
    vector<string> args = *m_args;
    if(args.size() == 0)
        //throw an error
        ;
    ManipulationCommandsParser::parseArgs(*this);
}

void ManipulationCommandsParser::parseArgs(DNAManipulationCommand &command)
{
    vector<string> args = *command.m_args;
    string identifier = args[s_dnaIdentifierArgIndex];
    if(identifier[s_dnaIdentifierArgIndex] == s_idIdentifier)
        *command.m_dnaSeq = DNADataHolder::getDNASequence(
                atoi(
                        identifier.substr(s_indexAfterIdentifier)
                                .c_str()
                ));
    else
        *command.m_dnaSeq = DNADataHolder::getDNASequence(
                identifier.substr(s_indexAfterIdentifier));
}
