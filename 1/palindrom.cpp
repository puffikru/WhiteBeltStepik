#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(const string& str)
{
    int l = 0;
    int r = str.size() - 1;
    while (l <= r)
    {
        if (str[l] != str[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

//int main()
//{
//    string str;
//    cin >> str;
//    cout << IsPalindrom(str) << endl;
//    return 0;
//}