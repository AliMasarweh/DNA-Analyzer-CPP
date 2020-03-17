//
// Created by ali-masa on 3/17/20.
//

#include "command.h"

Command::Command() : m_namedDnaSequencePntr(NULL) {}

std::string Command::notifyMessage()
{
    std::stringstream ss;
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
