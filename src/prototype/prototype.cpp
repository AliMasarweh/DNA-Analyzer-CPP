//
// Created by ali-masa on 2/2/20.
//
#include <iostream>
#include <string>
#include <assert.h>
#include "../model/dna_sequence.h"

using namespace std;

static DNASequence* cache[10];
static string statringCommand = "cmd <<< ";
enum commandsNames{ NEW, LOAD, SAVE, SLICE, REPLACE, CONCAT, PAIR };
static string commands[] = {"new", "load","save","slice",
                            "replace", "concat", "pair"};

void parseInput(string& basicString);

int main()
{
    DNASequence seq("ATG");
    string input;
    getline(cin, input);
    while(input != "quit")
    {
        parseInput(input);
        getline(cin, input);
    }
    cout << "QUITING!" << endl;
    return 0;
}

void parseInput(string& basicString) {
    assert(basicString.find(statringCommand) == 0);
    string operationAndArgs = basicString.substr(statringCommand.length());
    string op = operationAndArgs.substr(0, operationAndArgs.find(" "));

    if(op == commands[NEW]){

    }
}
