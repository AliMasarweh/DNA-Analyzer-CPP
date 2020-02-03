cmake_minimum_required(VERSION 3.15)
project(DNAnalyzer)

set(CMAKE_CXX_STANDARD 98)


include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(cmd cmd.cpp)
add_executable(prototype src/prototype/prototype.cpp
        src/model/dna_sequence.h src/model/dna_sequence.cpp
        src/model/nucleotide_analyzer.cpp src/model/nucleotide_analyzer.h
        src/model/codon_analyzer.cpp src/model/codon_analyzer.h src/prototype/indexed_dna_sequence.h)
