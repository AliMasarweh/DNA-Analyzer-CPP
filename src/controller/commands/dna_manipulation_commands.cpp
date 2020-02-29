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
    *m_dnaSeq = m_dnaSeq->slice(m_fromIndex, m_toIndex);

    // TODO:
    // <Id> <Name> <Seq>
    return __cxx11::string();
}

void SliceCommand::parseArgs()
{
    static size_t argsLength = 3,
        dnaIndetifierArgIndx = 0,
        fromIndxArgIndx = 1,
        endIndxArgIndx = 2;
    static size_t indexAfterIdntifier = 1;
    static char idIdentiger = '#';

    vector<string> args = *m_args;
    if(args.size() != argsLength)
        //throw an error
        ;
    string identifier = args[dnaIndetifierArgIndx];
    if(identifier[dnaIndetifierArgIndx] == idIdentiger)
        *m_dnaSeq = DNADataHolder::getDNASequence(
                atoi(
                        identifier.substr(indexAfterIdntifier)
                        .c_str()
                ));
    else
        *m_dnaSeq = DNADataHolder::getDNASequence(
                identifier.substr(indexAfterIdntifier));
    m_fromIndex = atoi(args[fromIndxArgIndx].c_str());
    m_fromIndex = atoi(args[endIndxArgIndx].c_str());
}

string ReplaceCommand::execute()
{
    DNASequence tmp = *(m_dnaSeq);
    for(map<size_t,char>::iterator iter = m_indexToNucleotide.begin();
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
    static size_t dnaIndetifierArgIndx = 0,
        indexAfterIdntifier = 1;
    static char idIdentiger = '#';

    vector<string> args = *m_args;
    if(args.size() % 2 != 1)
        //throw an error
        ;
    string identifier = args[dnaIndetifierArgIndx];
    if(identifier[dnaIndetifierArgIndx] == idIdentiger)
        *m_dnaSeq = DNADataHolder::getDNASequence(
                atoi(
                        identifier.substr(indexAfterIdntifier)
                                .c_str()
                ));
    else
        *m_dnaSeq = DNADataHolder::getDNASequence(
                identifier.substr(indexAfterIdntifier));

    args.erase(args.begin());
    for(int i = 0; i < args.size(); ++i)
    {
        size_t index = atoi(args[i].c_str());
        if(args[++i].c_str()[1] != 0)
            //throw an error
            ;
        char nucleotide = args[++i].c_str()[0];
        m_indexToNucleotide[index] = nucleotide;
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
    static size_t dnaIndetifierArgIndx = 0,
            indexAfterIdntifier = 1;
    static char idIdentiger = '#';

    vector<string> args = *m_args;
    if(args.size() % 2 != 1)
        //throw an error
        ;
    string identifier = args[dnaIndetifierArgIndx];
    if(identifier[dnaIndetifierArgIndx] == idIdentiger)
        *m_dnaSeq = DNADataHolder::getDNASequence(
                atoi(
                        identifier.substr(indexAfterIdntifier)
                                .c_str()
                ));
    else
        *m_dnaSeq = DNADataHolder::getDNASequence(
                identifier.substr(indexAfterIdntifier));

    args.erase(args.begin());
    DNASequence* dnaSequencePntr;
    for(int i = 0; i < args.size(); ++i)
    {
        string identifier = args[dnaIndetifierArgIndx];

        if(identifier[dnaIndetifierArgIndx] == idIdentiger)
            *dnaSequencePntr = DNADataHolder::getDNASequence(
                    atoi(
                            identifier.substr(indexAfterIdntifier)
                                    .c_str()
                    ));
        else
            *dnaSequencePntr = DNADataHolder::getDNASequence(
                    identifier.substr(indexAfterIdntifier));
        SharedPointer<DNASequence> sharedDnaSequencePntr(dnaSequencePntr);
        m_dnaSeqToConcat.push_back(
                sharedDnaSequencePntr
                        );
    }
}

string PairCommand::execute()
{
    *m_dnaSeq = m_dnaSeq->pairing();
    return __cxx11::string();
}

void PairCommand::parseArgs()
{
    static size_t dnaIndetifierArgIndx = 0,
            indexAfterIdntifier = 1;
    static char idIdentiger = '#';

    vector<string> args = *m_args;
    if(args.size() % 2 != 1)
        //throw an error
        ;
    string identifier = args[dnaIndetifierArgIndx];
    if(identifier[dnaIndetifierArgIndx] == idIdentiger)
        *m_dnaSeq = DNADataHolder::getDNASequence(
                atoi(
                        identifier.substr(indexAfterIdntifier)
                                .c_str()
                ));
    else
        *m_dnaSeq = DNADataHolder::getDNASequence(
                identifier.substr(indexAfterIdntifier));
}
