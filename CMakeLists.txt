cmake_minimum_required(VERSION 3.15)
project(DNAnalyzer)

set(CMAKE_CXX_STANDARD 98)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB controller_src "src/controller/*")
file(GLOB commands_src "src/controller/commands/*")
file(GLOB model_src "src/model/*")
file(GLOB view_src "src/view/*")

add_executable(prototype src/prototype/prototype.cpp src/model/dna_sequence.cpp
        src/model/nucleotide_analyzer.cpp src/model/codon_analyzer.cpp
        src/model/named_dna_sequence.h src/model/named_dna_sequence.cpp)

add_executable(contorol_tester main.cpp ${controller_src})

add_executable(view_tester src/view_tester.cpp ${view_src})

add_executable(dna_analyzer main.cpp
        ${controller_src}
        ${commands_src}
        ${model_src}
        ${view_src})
