//
// Created by ali-masa on 2/26/20.
//

#include "commands_factory.h"
#include "commands/dna_creation_commands.h"

using namespace std;

map<string, Command *> CommandsFactory::s_commandByOperationName =
        CommandsFactory::initCommands();

Command &CommandsFactory::CreateCommandFromOperation(
        vector<string >& operationAndArgs)
{
    string operation = operationAndArgs[0];
    operationAndArgs.erase(operationAndArgs.begin());
    if(s_commandByOperationName.find(operation) != s_commandByOperationName.end())
    {
        return s_commandByOperationName[operation]->putArgs(operationAndArgs);
    }
    throw CommandNotFoundException();
}

map<string, Command *> &CommandsFactory::initCommands()
{
    s_commandByOperationName["new"] = new NewCommand();
    s_commandByOperationName["dup"] = new DupCommand();
    s_commandByOperationName["load"] = new LoadCommand();

    return s_commandByOperationName;
}

void CommandsFactory::destructCommands()
{
    for(map<string, Command*>::iterator iter = s_commandByOperationName.begin();
        iter != s_commandByOperationName.end(); ++iter)
    {
        delete iter->second;
    }
}

CommandNotFoundException::CommandNotFoundException() :m_msg("Unknown command"){}

const char *CommandNotFoundException::what() const throw() {
    return m_msg.c_str();
}
