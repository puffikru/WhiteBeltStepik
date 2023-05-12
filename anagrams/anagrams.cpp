#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> BuildCharCounter(const string& word)
{
    map<char, int> result;
    for (const char& c : word)
    {
        ++result[c];
    }
    return result;
}

int main()
{
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        string word1, word2;
        cin >> word1 >> word2;
        if (BuildCharCounter(word1) == BuildCharCounter(word2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }
    return 0;
}