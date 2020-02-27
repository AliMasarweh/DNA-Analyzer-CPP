//
// Created by ali-masa on 2/26/20.
//

#include "commands_factory.h"
#include "commands/new_command.h"
#include "commands/dup_command.h"
#include "commands/load_command.h"

using namespace std;

map<string, Command *> CommandsFactory::s_commandByOperationName = CommandsFactory::initCommands();

Command &CommandsFactory::CreateCommandFromOperation(string& operation)
{
    if(s_commandByOperationName.find(operation) != s_commandByOperationName.end())
    {
        return *s_commandByOperationName[operation];
    }
    throw exception();
}

map<string, Command *> &CommandsFactory::initCommands()
{
    CommandsFactory::s_commandByOperationName;
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
