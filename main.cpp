//
// Created by ali-masa on 3/16/20.
//

#include <iostream>

#include "src/view/command_parser.h"
#include "src/view/operation.h"

#include "src/controller/commands_factory.h"

using namespace std;

int main()
{
    string input;
    CommandParser commandParser;
    getline(cin, input);
    while(input != "Exit")
    {
        Operation op = commandParser.parse(input);

        Command& command = CommandsFactory::CreateCommandFromOperation(op);
        command.execute();
        getline(cin, input);
    }

    CommandsFactory::destructCommands();
    return 0;
}