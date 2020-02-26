//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_NEW_COMMAND_H
#define DNANALYZER_NEW_COMMAND_H


#include "../command.h"

class NewCommand : public Command {
public:
    virtual std::string execute(std::string *args, size_t len);
};


#endif //DNANALYZER_NEW_COMMAND_H
