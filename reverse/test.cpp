#include <iostream>
#include "reverse.h"

using namespace std;

int main()
{
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for (int n : numbers)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}