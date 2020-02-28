//
// Created by ali-masa on 2/26/20.
//

#include "batch_command.h"

using namespace std;

string Batch::execute() {
    string ans = "";
    for(int i = 0; i < m_savedCommands.size(); ++i)
        ans += m_savedCommands[i]->execute();

    return ans;
}

void Batch::parseArgs() {}

Command &Batch::putArgs(vector<string> &args) {}
