//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_OPERATION_H
#define DNANALYZER_OPERATION_H

#include <string>
#include <vector>

class Operation
{
public:
    Operation();
    explicit Operation(std::string& name);
    Operation(std::string& name, std::vector<std::string>& args);
    void setName(std::string& name);
    void addTheArgs(std::vector<std::string>& args);

    std::string& getName();
    std::vector<std::string>& getArgs();
private:
    std::string m_name;
    std::vector<std::string> m_args;
};

#endif //DNANALYZER_OPERATION_H
