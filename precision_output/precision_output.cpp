#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream input("input.txt");

    if (input)
    {
        double num = 0.0;
        cout << fixed << setprecision(3);
        while (input >> num)
        {
            cout << num << endl;
        }
    }
    return 0;
}