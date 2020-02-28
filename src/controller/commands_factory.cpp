//
// Created by ali-masa on 2/26/20.
//

#include "commands_factory.h"
#include "commands/dna_creation_commands.h"

using namespace std;

map<string, SharedPointer<Command> > CommandsFactory::s_commandByOperationName =
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

map<string, SharedPointer<Command> > &CommandsFactory::initCommands()
{
    s_commandByOperationName["new"] = SharedPointer<Command>(
            new NewCommand());
    s_commandByOperationName["dup"] = SharedPointer<Command>(
            new DupCommand());
    s_commandByOperationName["load"] = SharedPointer<Command>(
            new LoadCommand());

    return s_commandByOperationName;
}

CommandNotFoundException::CommandNotFoundException() :m_msg("Unknown command"){}

const char *CommandNotFoundException::what() const throw() {
    return m_msg.c_str();
}
