//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_LOAD_COMMAND_H
#define DNANALYZER_LOAD_COMMAND_H


#include "../command.h"

class LoadCommand : public Command {
public:
    virtual std::string execute(std::string *args, size_t len);
};


#endif //DNANALYZER_LOAD_COMMAND_H
