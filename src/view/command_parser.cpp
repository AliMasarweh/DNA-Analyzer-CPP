//
// Created by ali-masa on 2/26/20.
//

#include <assert.h>
#include "command_parser.h"

using namespace std;

string CommandParser::startingCommand = "cmd <<< ";

Operation CommandParser::parse(string &input)
{
    checkCommandPrefix(input);
    string name = sliceUntilSpace(input);
    vector<std::string> args;
    while(hasMoreSpaces(input))
        args.push_back(sliceUntilSpace(input));
    args.push_back(input);

    return Operation(name, args);
}


void CommandParser::checkCommandPrefix(string &input)
{
    assert(input.find(startingCommand) == 0);
    input = input.substr(startingCommand.length());
}

string CommandParser::sliceUntilSpace(string &input)
{
    int indexOfSpace;
    string ans = input.substr(0, indexOfSpace = input.find(' '));
    input = input.substr(indexOfSpace + 1);
    return ans;
}

bool CommandParser::hasMoreSpaces(std::string &input)
{
    return input.find(' ') != string::npos;
}
