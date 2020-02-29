//
// Created by ali-masa on 2/28/20.
//

#ifndef DNANALYZER_DNA_DATA_HOLDER_H
#define DNANALYZER_DNA_DATA_HOLDER_H


#include <cstddef>
#include <map>
#include "../../../DNA-Sequence/dna_sequence.h"
#include "../../../SmartPointerExercise/shared_pointer.h"

class DNADataHolder {
public:
    static void addNamedDNA(/*NamedDNASequence& dnaSequence*/);
    static void addDNA(DNASequence& dnaSequence);
    static DNASequence& getDNASequence(size_t id);
    static DNASequence& getDNASequence(std::string name);

private:
    static std::map<size_t , SharedPointer<DNASequence> > s_idToDna;
    static std::map<std::string , SharedPointer<DNASequence> > s_nameToDna;
};


#endif //DNANALYZER_DNA_DATA_HOLDER_H
