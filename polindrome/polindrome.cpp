#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> PalindromFilter(const vector<string>& words, int minLength)
{
    vector<string> result;
    for (string word : words)
    {
        string orig = word;
        if (word.size() >= minLength)
        {
            reverse(word.begin(), word.end());
            if (orig == word)
            {
                result.push_back(word);
            }
        }
    }
    return result;
}

int main() {
    vector<string> words = {"abacaba", "aba", "weew", "bro", "code"};
    vector<string> palindroms = PalindromFilter(words, 3);
    for (const string palindrom : palindroms)
    {
        cout << palindrom << endl;
    }
    return 0;
}