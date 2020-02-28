//
// Created by ali-masa on 2/28/20.
//

#include "dna_creation_commands.h"

std::string NewCommand::execute() {
    return std::__cxx11::string();
}

void NewCommand::parseArgs() {

}

Command &NewCommand::putArgs(std::vector<std::string> &args) {
    m_args = args;
    return *this;
}

std::string LoadCommand::execute() {
    return std::__cxx11::string();
}

void LoadCommand::parseArgs() {

}

Command &LoadCommand::putArgs(std::vector<std::string> &args) {
    m_args = args;
    return *this;
}

std::string DupCommand::execute() {
    return std::__cxx11::string();
}

void DupCommand::parseArgs() {

}

Command &DupCommand::putArgs(std::vector<std::string> &args) {
    m_args = args;
    return *this;
}

DupCommand::DupCommand() {

}
