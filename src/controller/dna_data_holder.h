//
// Created by ali-masa on 2/28/20.
//

#ifndef DNANALYZER_DNA_DATA_HOLDER_H
#define DNANALYZER_DNA_DATA_HOLDER_H


#include <cstddef>
#include "../model/dna_sequence.h"
#include "../../../SmartPointerExercise/shared_pointer.h"

class dna_data_holder {
public:
    static void addIndexedDNA();
    static void addNamedDNA();
    static void addDNA();

private:
    static std::map<size_t , SharedPointer<DNASequence> > s_idToDna;
    static std::map<std::string , SharedPointer<DNASequence> > s_nameToDna;
};


#endif //DNANALYZER_DNA_DATA_HOLDER_H
