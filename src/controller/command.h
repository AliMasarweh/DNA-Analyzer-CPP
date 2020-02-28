//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_COMMAND_H
#define DNANALYZER_COMMAND_H

#include <string>

class Command
{
public:
    virtual std::string execute() = 0;
    virtual void parseArgs() = 0;
    virtual Command& putArgs(std::vector<std::string>& args) = 0;
};

#endif //DNANALYZER_COMMAND_H
