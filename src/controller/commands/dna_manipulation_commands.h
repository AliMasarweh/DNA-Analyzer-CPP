//
// Created by ali-masa on 2/29/20.
//

#ifndef DNANALYZER_DNA_MANIPULATION_COMMANDS_H
#define DNANALYZER_DNA_MANIPULATION_COMMANDS_H


#include <vector>
#include "../command.h"
#include "../../model/named_dna_sequence.h"
#include "../../../../SmartPointerExercise/shared_pointer.h"

class DNAManipulationCommand: public Command
{
public:
    virtual Command &putArgs(std::vector<std::string> &args);

protected:
    std::vector<std::string>* m_args;
};

class SliceCommand: public DNAManipulationCommand
{
public:
    virtual std::string execute();
    virtual void parseArgs();

private:
    SharedPointer<DNASequence> m_dnaSeq;
    size_t m_fromIndex;
    size_t m_toIndex;
};

class ReplaceCommand: public DNAManipulationCommand
{
public:
    virtual std::string execute();
    virtual void parseArgs();

private:
    SharedPointer<DNASequence> m_dnaSeq;
    std::map<size_t, char> m_indexToNucleotide;
};

class ConcatCommand: public DNAManipulationCommand
{
public:
    virtual std::string execute();
    virtual void parseArgs();

private:
    SharedPointer<DNASequence> m_dnaSeq;
    std::vector<SharedPointer<DNASequence> > m_dnaSeqToConcat;
};

class PairCommand: public DNAManipulationCommand
{
public:
    virtual std::string execute();
    virtual void parseArgs();

private:
    SharedPointer<DNASequence> m_dnaSeq;
};

#endif //DNANALYZER_DNA_MANIPULATION_COMMANDS_H
