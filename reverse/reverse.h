#pragma once

#include <vector>

using namespace std;

void Reverse(vector<int>& v)
{
    vector<int> result = v;
    v.clear();
    for (int i = result.size() - 1; i >= 0; --i)
    {
        v.push_back(result[i]);
    }
}