#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int Q;
    cin >> Q;

    set<string> unique;

    for (int i = 0; i < Q; ++i)
    {
        string word;
        cin >> word;

        unique.insert(word);
    }

    cout << unique.size() << endl;
    return 0;
}