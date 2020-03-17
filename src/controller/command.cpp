//
// Created by ali-masa on 3/17/20.
//

#include <iostream>
#include "command.h"

using namespace std;

Command::Command() : m_namedDnaSequencePntr(NULL) {}

string Command::notifyMessage()
{
    Observer o(cout);
    stringstream ss;
    if(m_namedDnaSequencePntr != NULL)
    {
        ss << "[" << m_namedDnaSequencePntr->getId() << "] "
           << m_namedDnaSequencePntr->getName() << " " << m_namedDnaSequencePntr->asString() << "\n";
    } else
    {
        ss << "NULL\n";
    }

    return ss.str();
}
