//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_COMMANDS_FACTORY_H
#define DNANALYZER_COMMANDS_FACTORY_H


#include <string>
#include "command.h"

class CommandsFactory
{
    static Command& CreateCommandFromOperation(std::string operation);
};


#endif //DNANALYZER_COMMANDS_FACTORY_H
