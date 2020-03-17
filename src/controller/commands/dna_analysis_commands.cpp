//
// Created by ali-masa on 3/16/20.
//

#include "dna_analysis_commands.h"
#include "../dna_data_holder.h"

using namespace std;

Command &DNAAnalysisCommands::putArgs(vector<string> &args)
{
    m_args = args;
    return *this;
}

void DNAAnalysisCommands::addExpression(std::string &expression) {}

void DNAAnalysisCommands::addNamedDNASeq(NamedDNASequence &namedDnaSequence) {}


void AnalysisCommandsParser::parseArgs(DNAAnalysisCommands &command)
{
    command.preValidator();

    // To get the NamedDNASeq by either id or name
    string identifier = command.m_args[s_dnaIdentifierArgIndex];
    *command.m_namedDnaSequencePntr = DNADataHolder::getDNASeqByIdentifier(identifier);
    command.m_args.erase(command.m_args.begin());

    command.postStaticParsingParser();
}

void AnalysisCommandsParser::parse2ndArgToExpressionOrNamedDNASeq(DNAAnalysisCommands &command)
{
    string expressionOrNamedDNA = command.m_args[s_secondArgIndex];
    if(expressionOrNamedDNA[0] == '#' || expressionOrNamedDNA[0] == '@')
        command.addNamedDNASeq(DNADataHolder::getDNASeqByIdentifier(expressionOrNamedDNA));
    else
        command.addExpression(expressionOrNamedDNA);
}

string LenCommand::execute()
{
    m_analysisAns.push_back(m_namedDnaSequencePntr->length());
    // TODO: Observer instead of return

    return __cxx11::string();
}

void LenCommand::parseArgs()
{
    AnalysisCommandsParser::parseArgs(*this);
}

void LenCommand::preValidator()
{
    if(m_args.size() != s_argsLength)
        // throw an error
        ;
    if(m_args[0].find('#') == string::npos || m_args[0].find('@') != string::npos)
        // throw first argument must be an id
        ;
}

void LenCommand::postStaticParsingParser() {}

string FindCommand::execute()
{
    if(this->m_expressedSeq == "")
    {
        m_analysisAns.push_back(this->m_namedDnaSequencePntr->find(m_namedDNASeq->asString()));
    } else
    {
        m_analysisAns.push_back(this->m_namedDnaSequencePntr->find(m_expressedSeq));
    }

    return __cxx11::string();
}

void FindCommand::parseArgs()
{
    AnalysisCommandsParser::parseArgs(*this);
}

void FindCommand::preValidator()
{
    if(m_args.size() != s_argsLength)
        //throw an error
        ;
}

void FindCommand::postStaticParsingParser()
{
    AnalysisCommandsParser::parse2ndArgToExpressionOrNamedDNASeq(*this);
}

void FindCommand::addExpression(std::string &expression)
{
    this->m_namedDNASeq = NULL;
    this->m_expressedSeq = expression;
}

void FindCommand::addNamedDNASeq(NamedDNASequence &namedDnaSequence)
{
    this->m_namedDNASeq = &namedDnaSequence;
    this->m_expressedSeq = "";
}

string CountCommand::execute()
{
    if(this->m_expressedSeq == "")
    {
        m_analysisAns.push_back(this->m_namedDnaSequencePntr->count(m_namedDNASeq->asString()));
    } else
    {
        m_analysisAns.push_back(this->m_namedDnaSequencePntr->count(m_expressedSeq));
    }

    return __cxx11::string();
}

void CountCommand::parseArgs()
{
    AnalysisCommandsParser::parse2ndArgToExpressionOrNamedDNASeq(*this);
}

void CountCommand::preValidator()
{
    if(m_args.size() != s_argsLength)
        //throw an error
        ;
}

void CountCommand::postStaticParsingParser()
{
    AnalysisCommandsParser::parse2ndArgToExpressionOrNamedDNASeq(*this);
}

void CountCommand::addExpression(std::string &expression)
{
    this->m_namedDNASeq = NULL;
    this->m_expressedSeq = expression;
}

void CountCommand::addNamedDNASeq(NamedDNASequence &namedDnaSequence)
{
    this->m_namedDNASeq = &namedDnaSequence;
    this->m_expressedSeq = "";
}

string FindAllCommand::execute()
{
    if(this->m_expressedSeq == "")
    {
        m_analysisAns = this->m_namedDnaSequencePntr->findAll(m_namedDNASeq->asString());
    } else
    {
        m_analysisAns = this->m_namedDnaSequencePntr->findAll(m_expressedSeq);
    }

    return __cxx11::string();
}

void FindAllCommand::parseArgs()
{
    AnalysisCommandsParser::parseArgs(*this);
}

void FindAllCommand::preValidator()
{
    if(m_args.size() != s_argsLength)
        //throw an error
        ;
}

void FindAllCommand::postStaticParsingParser()
{
    AnalysisCommandsParser::parse2ndArgToExpressionOrNamedDNASeq(*this);
}

void FindAllCommand::addExpression(std::string &expression)
{
    this->m_namedDNASeq = NULL;
    this->m_expressedSeq = expression;
}

void FindAllCommand::addNamedDNASeq(NamedDNASequence &namedDnaSequence)
{
    this->m_namedDNASeq = &namedDnaSequence;
    this->m_expressedSeq = "";
}
