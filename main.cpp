//
// Created by ali-masa on 3/16/20.
//

#include <iostream>

#include "view/command_parser.h"
#include "view/operation.h"

#include "controller/commands_factory.h"

using namespace std;

int main()
{
    string input;
    CommandParser commandParser;
    while(input != "Exit")
    {
        getline(cin, input);
        Operation op = commandParser.parse(input);

        Command& command = CommandsFactory::CreateCommandFromOperation(op);
        command.execute();
    }


    return 0;
}