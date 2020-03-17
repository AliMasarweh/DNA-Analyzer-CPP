//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_COMMAND_H
#define DNANALYZER_COMMAND_H

#include <string>
#include "../view/observer.h"
#include "../model/named_dna_sequence.h"

class Command: public Subject
{
public:
    Command();
    virtual std::string execute() = 0;
    virtual void parseArgs() = 0;
    virtual Command& putArgs(std::vector<std::string>& args) = 0;
    virtual ~Command() {}

    std::string notifyMessage();

protected:
    NamedDNASequence* m_namedDnaSequencePntr;
};

#endif //DNANALYZER_COMMAND_H
