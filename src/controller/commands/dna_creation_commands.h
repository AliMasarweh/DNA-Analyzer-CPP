//
// Created by ali-masa on 2/28/20.
//

#ifndef DNANALYZER_DNA_CREATION_COMMANDS_H
#define DNANALYZER_DNA_CREATION_COMMANDS_H

#include <vector>
#include <cstdlib>
#include "../command.h"

class DNACreationCommand : public Command
{
    friend class CreationCommandsParser;
protected:
    std::vector<std::string> m_args;

private:
    virtual void addParsedAgrs(std::string firstArg, std::string m_name = "") = 0;
};

class CreationCommandsParser
{
public:
    static void addParsedAgrs(DNACreationCommand& command);
};

class NewCommand : public DNACreationCommand {
public:
    virtual std::string execute();
    virtual void parseArgs();

private:
    inline void addParsedAgrs(std::string dnaSeq, std::string m_name);
    std::string m_dnaSeq;
    std::string m_name;
};

inline void NewCommand::addParsedAgrs(std::string dnaSeq, std::string name)
{
    m_dnaSeq = dnaSeq;
    m_name = name;
}

class LoadCommand : public DNACreationCommand {
public:
    virtual std::string execute();
    virtual void parseArgs();

private:
    inline void addParsedAgrs(std::string fileName, std::string m_name);
    std::string m_fileName;
    std::string m_name;
};

inline void LoadCommand::addParsedAgrs(std::string fileName, std::string name)
{
    m_fileName = fileName;
    m_name = name;
}

class DupCommand : public DNACreationCommand {
public:
    virtual std::string execute();
    virtual void parseArgs();

private:
    inline void addParsedAgrs(std::string sequenceId, std::string name);
    size_t m_sequenceId;
    std::string m_name;
};

inline void DupCommand::addParsedAgrs(std::string sequenceId, std::string name)
{
    m_sequenceId = std::atoi(sequenceId.c_str());
    m_name = name;
}


#endif //DNANALYZER_DNA_CREATION_COMMANDS_H
