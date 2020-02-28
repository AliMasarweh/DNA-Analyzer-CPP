cmake_minimum_required(VERSION 3.15)
project(DNAnalyzer)

set(CMAKE_CXX_STANDARD 98)


include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


file(GLOB_RECURSE MODEL_SRCS
        RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/model/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/model/*.h)

source_group(model FILES ${MODEL_SRCS})

add_executable(prototype src/prototype/prototype.cpp
        src/model/dna_sequence.h src/model/dna_sequence.cpp
        src/model/nucleotide_analyzer.cpp src/model/nucleotide_analyzer.h
        src/model/codon_analyzer.cpp src/model/codon_analyzer.h src/prototype/indexed_dna_sequence.h)


add_executable(controller_tester src/controller_tester.cpp src/controller/controller.h
        src/controller/commands_factory.h src/controller/commands_factory.cpp
        src/controller/controller.h src/controller/controller.cpp
        src/controller/commands/batch_command.h src/controller/commands/batch_command.cpp
        src/controller/commands/dna_creation_commands.h
        src/controller/commands/dna_creation_commands.cpp
        src/controller/dna_data_holder.h
        src/controller/dna_data_holder.cpp)

add_executable(view_tester src/view_tester.cpp src/view/parser.h src/view/parser.cpp
        src/view/operation.h src/view/operation.cpp)
