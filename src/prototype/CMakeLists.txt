cmake_minimum_required(VERSION 3.15)
project(Prototype)

set(CMAKE_CXX_STANDARD 98)

add_executable(Prototype prototype.cpp model/dna_sequence.h model/dna_sequence.cpp
        model/nucleotide_analyzer.cpp model/nucleotide_analyzer.h
        model/codon_analyzer.cpp model/codon_analyzer.h)
