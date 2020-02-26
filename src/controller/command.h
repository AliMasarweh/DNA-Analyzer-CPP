//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_COMMAND_H
#define DNANALYZER_COMMAND_H

#include <string>

class Command
{
public:
    virtual std::string execute(std::string args[], size_t len) = 0;
};

#endif //DNANALYZER_COMMAND_H
