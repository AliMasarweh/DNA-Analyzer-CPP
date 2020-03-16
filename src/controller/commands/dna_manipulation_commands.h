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
    friend class ManipulationCommandsParser;

public:
    virtual Command &putArgs(std::vector<std::string> &args);

protected:
    std::vector<std::string> m_args;
    SharedPointer<DNASequence> m_dnaSeq;

private:
    virtual void preValidator() = 0;
    virtual void postStaticParsingParser() = 0;
};

class ManipulationCommandsParser
{
public:
    static void parseArgs(DNAManipulationCommand& command);
    static DNASequence& getDNASeqByIdentifier(std::string identifier);

    /* For static parsing of the first sequence id or name */
    const static size_t s_dnaIdentifierArgIndex = 0;
    const static size_t s_indexAfterIdentifier = 1;
    const static char s_idIdentifier = '#';
};

class SliceCommand: public DNAManipulationCommand
{
public:
    virtual std::string execute();
    virtual void parseArgs();

private:
    virtual void preValidator();
    virtual void postStaticParsingParser();

    std::vector<size_t> m_indexes;
    const static size_t s_argsLength = 3;
    const static size_t s_fromIndxArgIndx = 1;
    const static size_t s_endIndxArgIndx = 2;
};

class ReplaceCommand: public DNAManipulationCommand
{
public:
    virtual std::string execute();
    virtual void parseArgs();

private:
    virtual void preValidator();
    virtual void postStaticParsingParser();

    std::vector<std::pair<size_t, char> > m_indexToNucleotide;
};

class ConcatCommand: public DNAManipulationCommand
{
public:
    virtual std::string execute();
    virtual void parseArgs();

private:
    const static size_t s_atLeastTwoDNASeq = 2;;
    virtual void preValidator();
    virtual void postStaticParsingParser();

    std::vector<SharedPointer<DNASequence> > m_dnaSeqToConcat;
};

class PairCommand: public DNAManipulationCommand
{
public:
private:
    virtual void preValidator();

    virtual void postStaticParsingParser();

public:
    virtual std::string execute();
    virtual void parseArgs();
};

#endif //DNANALYZER_DNA_MANIPULATION_COMMANDS_H
