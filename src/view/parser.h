//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_PARSER_H
#define DNANALYZER_PARSER_H


#include <string>
#include "operation.h"

class parser {
    static Operation parse(std::string& str);
};


#endif //DNANALYZER_PARSER_H
