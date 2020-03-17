//
// Created by ali-masa on 2/28/20.
//

#ifndef DNANALYZER_DNA_DATA_HOLDER_H
#define DNANALYZER_DNA_DATA_HOLDER_H


#include <cstddef>
#include <map>
#include "../../../DNA-Sequence/dna_sequence.h"
#include "../../../SmartPointerExercise/shared_pointer.h"
#include "../model/named_dna_sequence.h"

class DNADataHolder {
public:
    static void addDNA(NamedDNASequence& dnaSequence);
    static NamedDNASequence& getDNASequence(size_t id);
    static NamedDNASequence& getDNASequence(std::string name);
    static NamedDNASequence& getDNASeqByIdentifier(std::string identifier);

private:
    static std::map<size_t , SharedPointer<NamedDNASequence> > s_idToDNA;
    static std::map<std::string , SharedPointer<NamedDNASequence> > s_nameToDNA;

    const static size_t s_dnaIdentifierArgIndex = 0;
    const static char s_idIdentifier = '#';
};


#endif //DNANALYZER_DNA_DATA_HOLDER_H
