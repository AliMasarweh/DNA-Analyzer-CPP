//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_BATCH_H
#define DNANALYZER_BATCH_H


#include <vector>
#include "command.h"

class Batch : public Command{
public:
    virtual std::string execute(std::string *args, size_t len);

private:
    std::vector<Command*> m_savedCommands;
};


#endif //DNANALYZER_BATCH_H
