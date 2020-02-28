//
// Created by ali-masa on 2/28/20.
//

#include "dna_creation_commands.h"
#include "../../model/dna_sequence.h"
#include "../dna_data_holder.h"

using namespace std;

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
    if(m_args.size() == 1)
        addParsedAgrs(m_args[0]);
    else if(m_args.size() == 2) {
        if (m_args[1] != "")
            addParsedAgrs(m_args[0], m_args[1]);

        else
            // notify for an error
            ;
    }
}

Command &NewCommand::putArgs(vector<string> &args)
{
    m_args = args;
    return *this;
}

string LoadCommand::execute()
{
    parseArgs();
    DNASequence * dnaSequence = /*new NamedDNASequence(*/
            new DNASequence("A") /*, m_name)*/;
    dnaSequence->readFromFile(m_fileName);

    DNADataHolder::addDNA(*dnaSequence);

    /* <ID> NAME SEQ */
    return __cxx11::string();
}

void LoadCommand::parseArgs()
{
    if(m_args.size() == 1)
        addParsedAgrs(m_args[0]);
    else if(m_args.size() == 2) {
        if (m_args[1] != "")
            addParsedAgrs(m_args[0], m_args[1]);

        else
            // notify for an error
            ;
    }
}

Command &LoadCommand::putArgs(vector<string> &args)
{
    m_args = args;
    return *this;
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
    if(m_args.size() == 1)
        addParsedAgrs(m_args[0]);
    else if(m_args.size() == 2) {
        if (m_args[1] != "")
            addParsedAgrs(m_args[0], m_args[1]);

        else
            // notify for an error
            ;
    }
}

Command &DupCommand::putArgs(vector<string> &args)
{
    m_args = args;
    return *this;
}
