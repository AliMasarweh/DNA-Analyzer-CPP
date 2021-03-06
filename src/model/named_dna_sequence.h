//
// Created by ali-masa on 2/3/20.
//

#ifndef DNANALYZER_NAMED_DNA_SEQUENCE_H
#define DNANALYZER_NAMED_DNA_SEQUENCE_H

#include <sstream>
#include <cstring>
#include "dna_sequence.h"

class NamedDNASequence: public DNASequence
{
public:
    explicit NamedDNASequence(const char dnaSeq[], const char name[] = "");

    explicit NamedDNASequence(DNASequence& dnaSequence, const std::string name = "");

    explicit NamedDNASequence(const std::string& dnaSeq,
            const std::string name = "");

    inline size_t getId() const { return m_id; }

    inline const std::string &getName() const { return m_name; }

    inline static size_t generateId() { static size_t id = 0; return ++id;}

    void pairing();
    void slice(size_t from, size_t to);
    void replace(size_t index, char nuclutide);
    void concat(NamedDNASequence& other);

    static std::string generateName(size_t id);

private:
    size_t m_id;
    std::string m_name;
};

#endif //DNANALYZER_NAMED_DNA_SEQUENCE_H
