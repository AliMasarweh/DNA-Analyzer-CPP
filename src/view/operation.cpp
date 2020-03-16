//
// Created by ali-masa on 2/26/20.
//

#include "operation.h"


Operation::Operation() {}

Operation::Operation(std::string &name) : m_name(name) {}

Operation::Operation(std::string &name, std::vector<std::string> &args) :m_name(name), m_args(args) {}

void Operation::setName(std::string &name)
{
    this->m_name = name;
}

void Operation::addTheArgs(std::vector<std::string> &args)
{
    this->m_args = args;
}
