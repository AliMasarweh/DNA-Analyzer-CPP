//
// Created by ali-masa on 2/28/20.
//

#ifndef DNANALYZER_DNA_CREATION_COMMANDS_H
#define DNANALYZER_DNA_CREATION_COMMANDS_H

#include <vector>
#include "../command.h"

class NewCommand : public Command {
public:
    virtual std::string execute();
    virtual void parseArgs();
    virtual Command& putArgs(std::vector<std::string>& args);

private:
    std::vector<std::string> m_args;
};

class LoadCommand : public Command {
public:
    virtual std::string execute();
    virtual void parseArgs();
    virtual Command& putArgs(std::vector<std::string>& args);

private:
    std::vector<std::string> m_args;
};

class DupCommand : public Command {
public:
    virtual std::string execute();
    virtual void parseArgs();
    virtual Command& putArgs(std::vector<std::string>& args);

private:
    std::vector<std::string> m_args;
};



#endif //DNANALYZER_DNA_CREATION_COMMANDS_H
