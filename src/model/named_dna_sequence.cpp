//
// Created by ali-masa on 2/28/20.
//

#include "named_dna_sequence.h"

NamedDNASequence::NamedDNASequence(const char *dnaSeq, const char *name)
: DNASequence(dnaSeq),m_id(generateId()){
    if(*name != 0)
        this->m_name = name;
    else
        this->m_name = generateName(this->m_id);
}

NamedDNASequence::NamedDNASequence(DNASequence &dnaSequence, std::string name)
: DNASequence(dnaSequence), m_id(generateId())
{
    if(strcmp(name.c_str(), "") != 0)
        this->m_name = name;
    else
        this->m_name = generateName(this->m_id);
}

NamedDNASequence::NamedDNASequence(const std::string& dnaSeq, std::string name)
: DNASequence(dnaSeq), m_id(generateId()){
    if(strcmp(name.c_str(), "") != 0)
        this->m_name = name;
    else
        this->m_name = generateName(this->m_id);
}

std::string NamedDNASequence::generateName(size_t id)
{
    static std::string name = "seq";
    std::stringstream ss;
    ss << name << id;
    return ss.str();
}

void NamedDNASequence::pairing()
{
    this->m_sequence = DNASequence::pairing().asString();
}

void NamedDNASequence::slice(size_t from, size_t to)
{
    this->m_sequence = DNASequence::slice(from, to).asString();
}

void NamedDNASequence::replace(size_t index, char nuclutide)
{
    this->m_sequence.at(index) = nuclutide;
}

void NamedDNASequence::concat(NamedDNASequence &other)
{
    this->m_sequence = DNASequence::concat(other).asString();
}
