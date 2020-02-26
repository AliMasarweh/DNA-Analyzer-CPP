//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_CONTROLLER_H
#define DNANALYZER_CONTROLLER_H

#include <string>
#include "../view/operation.h"

class Controller
{
    std::string executeCommand(const Operation& op);
};

#endif //DNANALYZER_CONTROLLER_H
