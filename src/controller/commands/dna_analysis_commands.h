//
// Created by ali-masa on 3/16/20.
//

#ifndef DNANALYZER_DNA_ANALYSIS_COMMANDS_H
#define DNANALYZER_DNA_ANALYSIS_COMMANDS_H


#include <vector>
#include "../command.h"
#include "../../model/dna_sequence.h"
#include "../../../../SmartPointerExercise/shared_pointer.h"

class DNAAnalysisCommands: public Command
{
public:
    virtual Command &putArgs(std::vector<std::string> &args);

protected:
    std::vector<std::string> m_args;
    SharedPointer<DNASequence> m_dnaSeq;

private:
    virtual void preValidator() = 0;
    virtual void postStaticParsingParser() = 0;
};


class LenCommand : public DNAAnalysisCommands
{

};

class FindCommand : public DNAAnalysisCommands
{

};

class CountCommand : public DNAAnalysisCommands
{

};

class FindAllCommand : public DNAAnalysisCommands
{

};

#endif //DNANALYZER_DNA_ANALYSIS_COMMANDS_H
