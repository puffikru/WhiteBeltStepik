#include <iostream>

using namespace std;

class Incognizable
{
public:
    Incognizable(){}

    Incognizable(int value)
    {
        a = value;
    }

    Incognizable(int a, int b)
    {
        a = a;
        b = b;
    }

private:
    int a;
    int b;
};

// int main()
// {
//     Incognizable a;
//     Incognizable b = {};
//     Incognizable c = {0};
//     Incognizable d = {0, 1};

//     return 0;
// }