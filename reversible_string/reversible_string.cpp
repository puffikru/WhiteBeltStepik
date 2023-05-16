#include <iostream>
#include <string>

using namespace std;

class ReversibleString
{
public:
    ReversibleString() {};

    ReversibleString(const string& str)
    {
        row = str;
    }

    void Reverse()
    {
        string result;
        for (int i = row.size() - 1; i >= 0; --i)
        {
            result += row[i];
        }
        row = result;
    }

    string ToString() const 
    {
        return row;
    }
private:
    string row;
};


// int main()
// {
//     ReversibleString s("live");
//     s.Reverse();
//     cout << s.ToString() << endl;
    
//     s.Reverse();
//     const ReversibleString& s_ref = s;
//     string tmp = s_ref.ToString();
//     cout << tmp << endl;
    
//     ReversibleString empty;
//     cout << '"' << empty.ToString() << '"' << endl;

//     return 0;
// }