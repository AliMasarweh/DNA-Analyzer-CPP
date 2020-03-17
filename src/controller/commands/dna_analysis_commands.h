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
    friend class AnalysisCommandsParser;

public:
    virtual Command &putArgs(std::vector<std::string> &args);

protected:
    std::vector<std::string> m_args;
    std::vector<size_t> m_analysisAns;

private:
    virtual void preValidator() = 0;
    virtual void postStaticParsingParser() = 0;
    virtual void addExpression(std::string& expression);
    virtual void addNamedDNASeq(NamedDNASequence& namedDnaSequence);
};

class AnalysisCommandsParser
{
public:
    static void parseArgs(DNAAnalysisCommands& command);
    static void parse2ndArgToExpressionOrNamedDNASeq(DNAAnalysisCommands& command);

    /* For static parsing of the first sequence id or name */
    const static size_t s_dnaIdentifierArgIndex = 0,
            s_secondArgIndex = 1;
};

class LenCommand : public DNAAnalysisCommands
{
public:
    virtual std::string execute();
    virtual void parseArgs();

private:
    virtual void preValidator();
    virtual void postStaticParsingParser();

    const static size_t s_argsLength = 1;
};

class FindCommand : public DNAAnalysisCommands
{
public:
    virtual std::string execute();
    virtual void parseArgs();
private:
    virtual void preValidator();
    virtual void postStaticParsingParser();

    virtual void addExpression(std::string &expression);
    virtual void addNamedDNASeq(NamedDNASequence &namedDnaSequence);

    const static size_t s_argsLength = 2;
    std::string m_expressedSeq;
    NamedDNASequence* m_namedDNASeq;
};

class CountCommand : public DNAAnalysisCommands
{
public:
    virtual std::string execute();
    virtual void parseArgs();

private:
    virtual void preValidator();
    virtual void postStaticParsingParser();

    virtual void addExpression(std::string &expression);
    virtual void addNamedDNASeq(NamedDNASequence &namedDnaSequence);

    const static size_t s_argsLength = 2;
    std::string m_expressedSeq;
    NamedDNASequence* m_namedDNASeq;
};

class FindAllCommand : public DNAAnalysisCommands
{
public:
    virtual std::string execute();
    virtual void parseArgs();

private:
    virtual void preValidator();
    virtual void postStaticParsingParser();

    virtual void addExpression(std::string &expression);
    virtual void addNamedDNASeq(NamedDNASequence &namedDnaSequence);

    const static size_t s_argsLength = 2;
    std::string m_expressedSeq;
    NamedDNASequence* m_namedDNASeq;
};

#endif //DNANALYZER_DNA_ANALYSIS_COMMANDS_H
