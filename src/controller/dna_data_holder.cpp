//
// Created by ali-masa on 2/28/20.
//

#include <cstdlib>
#include "dna_data_holder.h"

using namespace std;

map<size_t, SharedPointer<NamedDNASequence> > DNADataHolder::s_idToDNA;
map<string, SharedPointer<NamedDNASequence> > DNADataHolder::s_nameToDNA;

void DNADataHolder::addDNA(NamedDNASequence &dnaSequence)
{
    SharedPointer<NamedDNASequence> sharedPointerOfNamedDNASeq(&dnaSequence);
    s_idToDNA.insert(make_pair(dnaSequence.getId(), sharedPointerOfNamedDNASeq));
    s_nameToDNA.insert(make_pair(dnaSequence.getName(), sharedPointerOfNamedDNASeq));
}

NamedDNASequence &DNADataHolder::getDNASequence(size_t id)
{
    return *s_idToDNA[id];
}

NamedDNASequence &DNADataHolder::getDNASequence(string name)
{
    return *s_nameToDNA[name];
}

NamedDNASequence &DNADataHolder::getDNASeqByIdentifier(std::string identifier)
{
    if(identifier[s_dnaIdentifierArgIndex] == s_idIdentifier)
        return DNADataHolder::getDNASequence(
                atoi(
                        identifier.substr(s_dnaIdentifierArgIndex+1)
                                .c_str()
                ));
    else
        return DNADataHolder::getDNASequence(
                identifier.substr(s_dnaIdentifierArgIndex+1));
}
