//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_BATCH_COMMAND_H
#define DNANALYZER_BATCH_COMMAND_H


#include <vector>
#include "../command.h"

class Batch : public Command{
public:
    virtual std::string execute();
    virtual void parseArgs();
    virtual Command& putArgs(std::vector<std::string>& args);
    // load & save

private:
    std::vector<Command*> m_savedCommands;
};


#endif //DNANALYZER_BATCH_COMMAND_H
