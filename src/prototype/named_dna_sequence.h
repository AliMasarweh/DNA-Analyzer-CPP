//
// Created by ali-masa on 2/3/20.
//

#ifndef DNANALYZER_NAMED_DNA_SEQUENCE_H
#define DNANALYZER_NAMED_DNA_SEQUENCE_H

#include <sstream>
#include <cstring>
#include "../model/dna_sequence.h"

class NamedDNASequence: public DNASequence
{
public:
    explicit NamedDNASequence(const char dnaSeq[], const char name[] = NULL) : DNASequence(dnaSeq),
        m_id(generateId()){
        if(name)
            this->m_name = name;
        else
            this->m_name = generateName(this->m_id);
    }

    explicit NamedDNASequence(const std::string dnaSeq,
            const std::string name = "")
        : DNASequence(dnaSeq), m_id(generateId()){
        if(strcmp(name.c_str(), "") != 0)
            this->m_name = name;
        else
            this->m_name = generateName(this->m_id);
    }

    size_t getId() const {
        return m_id;
    }

    const std::string &getName() const {
        return m_name;
    }

    static size_t generateId()
    {
        static size_t id = 0;
        return ++id;
    }

    static std::string generateName(size_t id)
    {
        static std::string name = "seq";
        std::stringstream ss;
        ss << name << id;
        return ss.str();
    }

private:
    size_t m_id;
    std::string m_name;
};

#endif //DNANALYZER_NAMED_DNA_SEQUENCE_H
