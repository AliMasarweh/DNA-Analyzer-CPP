//
// Created by ali-masa on 2/2/20.
//
#include <iostream>
#include <string>
#include <assert.h>
#include <cstdlib>
#include "named_dna_sequence.h"
using namespace std;


class Cache{
public:
    static map<size_t, NamedDNASequence*> idToDNASequence;
};
map<size_t, NamedDNASequence*> Cache::idToDNASequence;

class CommandsParser{
public:
    static void parseInputCommand(string& basicString);

private:
    static void parseStartingCommand(string& basicString);
    static void sliceUntillSpace(string& basicString);
    class Creational{
    public:
        static string parseSeqOrFileArgument(string& basicString);
        static string parseNameArgumentIfExists(string& basicString);
    };
    static string statringCommand;
    enum commandsNames{ NEW, LOAD, DUP, SLICE, REPLACE, CONCAT, PAIR };
    static string commands[];
};

string CommandsParser::statringCommand = "cmd <<< ";
string CommandsParser::commands[] = { "new", "load", "dup","slice",
                     "replace", "concat", "pair"};

int main()
{
    DNASequence seq("ATG");
    string input;
    getline(cin, input);
    while(input != "quit")
    {
        CommandsParser::parseInputCommand(input);
        getline(cin, input);
    }
    cout << "QUITING!" << endl;
    return 0;
}

void CommandsParser::parseInputCommand(string& basicString)
{
    parseStartingCommand(basicString);
    string op = basicString.substr(0,basicString.find(" "));
    sliceUntillSpace(basicString);
    /* TODO: Fix Namming Bug
     * DUP has segmentation fault bug
     * */
    if(op == commands[NEW]){
        /*string seq = basicString.
                substr(0, basicString.find(" "));
        sliceUntillSpace(basicString);
        if(basicString.find("@") == 0)
            NamedDNASequence indexedDnaSequence(seq,
                    basicString.substr(1));
        else
            NamedDNASequence indexedDnaSequence(seq);*/

        NamedDNASequence indexedDnaSequence(
                Creational::parseSeqOrFileArgument(basicString),
                Creational::parseNameArgumentIfExists(basicString));
        Cache::idToDNASequence[indexedDnaSequence.getId()] =
                new NamedDNASequence(indexedDnaSequence);
        cout << '[' << indexedDnaSequence.getId() << "] "  <<
            indexedDnaSequence.getName() << ' ' << indexedDnaSequence.asString()
            << endl;
    } else if(op == commands[DUP]){
        string id = Creational::parseSeqOrFileArgument(basicString);
        assert(id[0] == '#');
        size_t idAsNumber = atoi(id.substr(1).c_str());
        NamedDNASequence indexedDnaSequence(
                Cache::idToDNASequence[idAsNumber]->asString(),
                Creational::parseNameArgumentIfExists(basicString));
        Cache::idToDNASequence[indexedDnaSequence.getId()] =
                new NamedDNASequence(indexedDnaSequence);
        cout << '[' << indexedDnaSequence.getId() << "] "  <<
             indexedDnaSequence.getName() << ' ' << indexedDnaSequence.asString()
             << endl;
    } else if(op == commands[LOAD]){
        string path = Creational::parseSeqOrFileArgument(basicString);
        NamedDNASequence indexedDnaSequence("A",
                Creational::parseNameArgumentIfExists(basicString));
        indexedDnaSequence.readFromFile(path);
        Cache::idToDNASequence[indexedDnaSequence.getId()] =
                &indexedDnaSequence;
        cout << '[' << indexedDnaSequence.getId() << "] "  <<
             indexedDnaSequence.getName() << ' ' << indexedDnaSequence.asString()
             << endl;
    }
    else if(op == commands[SLICE]){
        // id parsing
        string id = Creational::parseSeqOrFileArgument(basicString);
        assert(id[0] == '#');
        size_t idAsNumber = atoi(id.substr(1).c_str());
        sliceUntillSpace(basicString);

        string start = Creational::parseSeqOrFileArgument(basicString);
        size_t startAsNumber = atoi(start.c_str());
        sliceUntillSpace(basicString);

        string end = Creational::parseSeqOrFileArgument(basicString);
        size_t endAsNumber = atoi(end.c_str());

        NamedDNASequence indexedDnaSequence(
                Cache::idToDNASequence[idAsNumber]->
                slice(startAsNumber, endAsNumber).asString(), "");

        Cache::idToDNASequence[indexedDnaSequence.getId()] =
                new NamedDNASequence(indexedDnaSequence);
        cout << '[' << indexedDnaSequence.getId() << "] "  <<
             indexedDnaSequence.getName() << ' ' << indexedDnaSequence.asString()
             << endl;
    } else if(op == commands[REPLACE]){

    } else if(op == commands[CONCAT]){

    } else if(op == commands[PAIR]){
        string id = Creational::parseSeqOrFileArgument(basicString);
        assert(id[0] == '#');
        size_t idAsNumber = atoi(id.substr(1).c_str());

        NamedDNASequence indexedDnaSequence(
                Cache::idToDNASequence[idAsNumber]->
                        pairing().asString(), "");

        Cache::idToDNASequence[indexedDnaSequence.getId()] =
                new NamedDNASequence(indexedDnaSequence);
        cout << '[' << indexedDnaSequence.getId() << "] "  <<
             indexedDnaSequence.getName() << ' ' << indexedDnaSequence.asString()
             << endl;
    }
}

void CommandsParser::parseStartingCommand(string& basicString)
{
    assert(basicString.find(statringCommand) == 0);
    basicString = basicString.substr(statringCommand.length());
}

void CommandsParser::sliceUntillSpace(string& basicString)
{
    size_t indx = string::npos;
    if((indx = basicString.find(" ")) != string::npos)
        basicString = basicString.substr(indx+1);
}

string CommandsParser::Creational::
    parseSeqOrFileArgument(string& basicString)
{
    return basicString.substr(0, basicString.find(" "));
}

string CommandsParser::Creational::
parseNameArgumentIfExists(string& basicString)
{
    sliceUntillSpace(basicString);
    if(basicString.find("@") == 0)
        return basicString;
    return "";
}