//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_COMMAND_PARSER_H
#define DNANALYZER_COMMAND_PARSER_H

#include <string>
#include "operation.h"

class CommandParser {
public:
    Operation parse(std::string& str);

private:
    static std::string startingCommand;
    void checkCommandPrefix(std::string& input);
    std::string sliceUntilSpace(std::string& input);
    bool hasMoreSpaces(std::string& input);
};

#endif //DNANALYZER_COMMAND_PARSER_H
