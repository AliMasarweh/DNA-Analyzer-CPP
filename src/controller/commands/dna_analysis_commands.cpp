//
// Created by ali-masa on 3/16/20.
//

#include "dna_analysis_commands.h"

Command &DNAAnalysisCommands::putArgs(std::vector<std::string> &args)
{
    m_args = args;
    return *this;
}
