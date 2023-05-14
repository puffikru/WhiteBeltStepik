#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    int Q;
    cin >> Q;

    map<string, set<string>> sinonims;

    for (int i = 0; i < Q; ++i)
    {
        string command;
        cin >> command;

        if (command == "ADD")
        {
            string word1, word2;
            cin >> word1 >> word2;

            sinonims[word1].insert(word2);
            sinonims[word2].insert(word1);
        }
        else if (command == "COUNT")
        {
            string word;
            cin >> word;
            
            cout << sinonims[word].size() << endl;
        }
        else if (command == "CHECK")
        {
            string word1, word2;
            cin >> word1 >> word2;

            if ((sinonims.count(word1) > 0 && sinonims[word1].count(word2) > 0) || (sinonims.count(word2) > 0 && sinonims[word2].count(word1) > 0))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}