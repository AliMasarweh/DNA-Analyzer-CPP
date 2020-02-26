//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_COMMAND_H
#define DNANALYZER_COMMAND_H

#include <string>

class Command
{
    virtual std::string execute(std::string args[]);
};

#endif //DNANALYZER_COMMAND_H
