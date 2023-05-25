#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    ifstream input("input.txt");
    vector<vector<int>> table;
    if (input)
    {
        int N, M;
        input >> N >> M;
        int num = 0;
        for (int i = 0; i < N; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < M; ++j)
            {
                input >> num;
                temp.push_back(num);
                input.ignore(1);
            }
            table.push_back(temp);
        }
    }
    // cout << setfill(' ');
    for (int i = 0; i < table.size(); ++i)
    {
        for (int j = 0; j < table[i].size(); ++j)
        {
            cout << setw(10) << table[i][j];
            if (j < table[i].size() - 1)
            {
                cout << " ";
            }
        }
        if (i < table.size() - 1)
        {
            cout << endl;
        }
    }
    return 0;
}