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
    DNASequence * dnaSequence = /*new NamedDNASequence(*/
            new DNASequence(m_dnaSeq) /*, m_name)*/;

    DNADataHolder::addDNA(*dnaSequence);

    /* <ID> NAME SEQ */
    return __cxx11::string();
}

void NewCommand::parseArgs()
{
    CreationCommandsParser::addParsedAgrs(*this);
}

string LoadCommand::execute()
{
    parseArgs();
    DNASequence * dnaSequence = /*new NamedDNASequence(*/
            new DNASequence("A") /*, m_name)*/;

    // read from file should be static
    dnaSequence->readFromFile(m_fileName);

    DNADataHolder::addDNA(*dnaSequence);

    /* <ID> NAME SEQ */
    return __cxx11::string();
}

void LoadCommand::parseArgs()
{
    CreationCommandsParser::addParsedAgrs(*this);
}

string DupCommand::execute()
{
    parseArgs();
    DNASequence * dnaSequence = /*new NamedDNASequence(*/
            new DNASequence(
                    DNADataHolder::getDNASequenceById(m_sequenceId))
                    /*, m_name)*/;

    DNADataHolder::addDNA(*dnaSequence);

    /* <ID> NAME SEQ */
    return __cxx11::string();
}

void DupCommand::parseArgs()
{
    CreationCommandsParser::addParsedAgrs(*this);
}

void CreationCommandsParser::addParsedAgrs(DNACreationCommand &command)
{
    if(command.m_args.size() == 1)
        command.addParsedAgrs(command.m_args[0]);
    else if(command.m_args.size() == 2) {
        if (command.m_args[1] != "")
            command.addParsedAgrs(command.m_args[0],
                    command.m_args[1]);

        else
            // notify for an error
            ;
    }
}
