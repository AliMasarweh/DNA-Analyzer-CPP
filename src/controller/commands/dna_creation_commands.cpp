//
// Created by ali-masa on 2/28/20.
//

#include "dna_creation_commands.h"
#include "../dna_data_holder.h"

using namespace std;

Command &DNACreationCommand::putArgs(std::vector<std::string> &args)
{
    m_args = args;
    return *this;
}

string NewCommand::execute()
{
    parseArgs();
    m_namedDnaSequencePntr = /*new NamedDNASequence(*/
            new NamedDNASequence(m_dnaSeq) /*, m_name)*/;

    DNADataHolder::addDNA(*m_namedDnaSequencePntr);
    this->notifyMessage();

    /* <ID> NAME SEQ */
    return __cxx11::string();
}

void NewCommand::parseArgs()
{
    CreationCommandsParser::parseArgs(*this);
}

void NewCommand::addParsedAgrs(std::string dnaSeq, std::string name)
{
    m_dnaSeq = dnaSeq;
    m_name = name;
}

string LoadCommand::execute()
{
    parseArgs();
    m_namedDnaSequencePntr= /*new NamedDNASequence(*/
            new NamedDNASequence("A") /*, m_name)*/;

    // read from file should be static
    m_namedDnaSequencePntr->readFromFile(m_fileName);

    DNADataHolder::addDNA(*m_namedDnaSequencePntr);
    this->notifyMessage();

    /* <ID> NAME SEQ */
    return __cxx11::string();
}

void LoadCommand::parseArgs()
{
    CreationCommandsParser::parseArgs(*this);
}

string DupCommand::execute()
{
    parseArgs();
    m_namedDnaSequencePntr = /*new NamedDNASequence(*/
            new NamedDNASequence(
                    DNADataHolder::getDNASequence(m_sequenceId))
                    /*, m_name)*/;

    DNADataHolder::addDNA(*m_namedDnaSequencePntr);
    this->notifyMessage();
    /* <ID> NAME SEQ */
    return __cxx11::string();
}

void DupCommand::parseArgs()
{
    CreationCommandsParser::parseArgs(*this);
}

void CreationCommandsParser::parseArgs(DNACreationCommand &command)
{
    if(command.m_args.size() == 1)
        command.addParsedAgrs(command.m_args.at(0));
    else if(command.m_args.size() == 2) {
        if (command.m_args.at(1) != "")
            command.addParsedAgrs(command.m_args.at(0),
                    command.m_args.at(1));

        else
            // notify for an error
            ;
    }
}
