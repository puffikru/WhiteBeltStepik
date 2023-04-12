#include <iostream>

#include "move_strings.h"

using namespace std;

int main()
{
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    cout << "source size: " << source.size() << endl;
    for (string d : destination)
    {
        cout << d << " ";
    }
    return 0;
}