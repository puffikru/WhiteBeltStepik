// #pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void query()
{
    int Q;
    cin >> Q;
    string command;
    vector<bool> query;
    for (int i = 0; i < Q; ++i)
    {
        int N;
        cin >> command;
        if (command == "WORRY")
        {
            cin >> N;
            query[N] = true;
        } else if (command == "QUIET")
        {
            cin >> N;
            query[N] = false;
        } else if (command == "COME")
        {
            cin >> N;
            if (N > 0)
            {
                for (int i = 0; i < N; ++i)
                {
                    query.push_back(false);
                }
            } else 
            {
                for (int i = N; i < 0; ++i)
                {
                    query.pop_back();
                }
            }
        } else if (command == "WORRY_COUNT")
        {
            int worry_count = 0;
            for (bool q : query)
            {
                if (q) worry_count++; 
            }
            cout << worry_count << endl;
        }
    }
}
