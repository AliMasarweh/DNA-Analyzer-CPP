//
// Created by ali-masa on 2/26/20.
//

#ifndef DNANALYZER_COMMANDS_FACTORY_H
#define DNANALYZER_COMMANDS_FACTORY_H


#include <string>
#include <map>
#include <vector>

#include "../../../SmartPointerExercise/shared_pointer.h"
#include "command.h"

class CommandsFactory
{
public:
    static Command& CreateCommandFromOperation(
            std::vector<std::string>& operation);
    static std::map<std::string, SharedPointer<Command> > s_commandByOperationName;

private:
    static std::map<std::string, SharedPointer<Command> >& initCommands();
};


class CommandNotFoundException : public std::exception
{
public:
    explicit CommandNotFoundException();
    virtual ~CommandNotFoundException() throw (){}
    virtual const char* what() const throw ();

protected:
    std::string m_msg;
};

#endif //DNANALYZER_COMMANDS_FACTORY_H
