//
// Created by ali-masa on 2/26/20.
//

#include "commands_factory.h"
#include "commands/dna_creation_commands.h"
#include "../model/named_dna_sequence.h"

using namespace std;

map<string, SharedPointer<Command> > CommandsFactorySharedPointer::s_commandByOperationName =
        CommandsFactorySharedPointer::initCommands();

Command &CommandsFactorySharedPointer::CreateCommandFromOperation(
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

Command& CommandsFactorySharedPointer::CreateCommandFromOperation(
        Operation& operation)
{
    string operationName = operation.getName();
    vector<string> args = operation.getArgs();
    map<string, SharedPointer<Command> > stam = s_commandByOperationName;
    if(s_commandByOperationName.find(operationName) != s_commandByOperationName.end())
    {
        SharedPointer<Command> sharedPointer = s_commandByOperationName[operationName];
        sharedPointer.use_count();
        return s_commandByOperationName[operationName].get()->putArgs(args);
    }
    throw CommandNotFoundException();
}

map<string, SharedPointer<Command> > CommandsFactorySharedPointer::initCommands()
{
    map<string, SharedPointer<Command> > ans;
    ans.insert(make_pair("new", SharedPointer<Command>(
            new NewCommand())));
    ans.insert(make_pair("dup", SharedPointer<Command>(
            new DupCommand())));
    ans.insert(make_pair("load", SharedPointer<Command>(
            new LoadCommand())));

    return ans;
}

CommandNotFoundException::CommandNotFoundException() :m_msg("Unknown command"){}

const char *CommandNotFoundException::what() const throw()
{
    return m_msg.c_str();
}


map<string, Command*> CommandsFactory::s_commandByOperationName =
        CommandsFactory::initCommands();

Command &CommandsFactory::CreateCommandFromOperation(std::vector<std::string> &operationAndArgs)
{
    string operation = operationAndArgs[0];
    operationAndArgs.erase(operationAndArgs.begin());
    if(s_commandByOperationName.find(operation) != s_commandByOperationName.end())
    {
        return s_commandByOperationName[operation]->putArgs(operationAndArgs);
    }
    throw CommandNotFoundException();
}

Command &CommandsFactory::CreateCommandFromOperation(Operation &operation)
{
    string operationName = operation.getName();
    vector<string> args = operation.getArgs();
    if(s_commandByOperationName.find(operationName) != s_commandByOperationName.end())
    {
        return s_commandByOperationName[operationName]->putArgs(args);
    }
    throw CommandNotFoundException();
}

std::map<std::string, Command *> CommandsFactory::initCommands()
{
    map<string, Command*> ans;
    ans.insert(make_pair("new", new NewCommand()));
    ans.insert(make_pair("dup", new DupCommand()));
    ans.insert(make_pair("load", new LoadCommand()));

    return ans;
}

void CommandsFactory::destructCommands()
{

    for (map<string, Command *>::iterator i = s_commandByOperationName.begin();
            i != s_commandByOperationName.end(); ++i)
    {
        delete i->second;
    }
}
