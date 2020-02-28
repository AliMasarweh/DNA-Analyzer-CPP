//
// Created by ali-masa on 2/28/20.
//

#ifndef DNANALYZER_DNA_CREATION_COMMANDS_H
#define DNANALYZER_DNA_CREATION_COMMANDS_H

#include <vector>
#include "../command.h"

class CreationCommandsParser
{
    static void addParsedAgrs(Command& command);
};

class NewCommand : public Command {
public:
    virtual std::string execute();
    virtual void parseArgs();
    virtual Command& putArgs(std::vector<std::string>& args);

private:
    std::vector<std::string> m_args;

    void addParsedAgrs(std::string dnaSeq, std::string m_name = "");
    std::string m_dnaSeq;
    std::string m_name;
};

class LoadCommand : public Command {
public:
    virtual std::string execute();
    virtual void parseArgs();
    virtual Command& putArgs(std::vector<std::string>& args);

private:
    std::vector<std::string> m_args;

    void addParsedAgrs(std::string fileName, std::string m_name = "");
    std::string m_fileName;
    std::string m_name;
};

class DupCommand : public Command {
public:
    virtual std::string execute();
    virtual void parseArgs();
    virtual Command& putArgs(std::vector<std::string>& args);

private:
    std::vector<std::string> m_args;

    void addParsedAgrs(std::string sequenceId, std::string m_name = "");
    size_t m_sequenceId;
    std::string m_name;
};



#endif //DNANALYZER_DNA_CREATION_COMMANDS_H
