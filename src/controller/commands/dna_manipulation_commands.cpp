//
// Created by ali-masa on 2/29/20.
//

#include <cstdlib>
#include "dna_manipulation_commands.h"
#include "../dna_data_holder.h"

using namespace std;

string SliceCommand::execute() {
    *m_dnaSeq = m_dnaSeq->slice(m_fromIndex, m_toIndex);

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

Command &SliceCommand::putArgs(vector<string> &args)
{
    m_args = &args;
    return *this;
}

string ReplaceCommand::execute() {
    return __cxx11::string();
}

void ReplaceCommand::parseArgs() {

}

Command &ReplaceCommand::putArgs(vector<string> &args) {
    return <#initializer#>;
}

string ConcatCommand::execute() {
    return __cxx11::string();
}

void ConcatCommand::parseArgs() {

}

Command &ConcatCommand::putArgs(vector<string> &args) {
    return <#initializer#>;
}

string PairCommand::execute() {
    return __cxx11::string();
}

void PairCommand::parseArgs() {

}

Command &PairCommand::putArgs(vector<string> &args) {
    return <#initializer#>;
}
