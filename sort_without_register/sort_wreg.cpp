#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string ToLower(string& str)
{
    string result;
    for (char s : str)
    {   
        result += tolower(s);
    }
    return result;
}

int main()
{
    int N;
    cin >> N;

    vector<string> strings;

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        strings.push_back(str);
    }
    sort(begin(strings), end(strings), [](string a, string b){
        return ToLower(a) < ToLower(b);
    });

    for (const auto& s : strings)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}