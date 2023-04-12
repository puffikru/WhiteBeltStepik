#pragma once

using namespace std;

#include <string>
#include <vector>

void MoveStrings(vector<string>& source, vector<string>& destination)
{
    for (string s : source)
    {
        destination.push_back(s);
    }
    source.clear();
}