#include <iostream>

#include "reversed.h"

using namespace std;

int main()
{
    vector<int> numbers = {1, 5, 3, 4, 2};
    vector<int> reversed = Reversed(numbers);
    for (int r : reversed)
    {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}