#include <iostream>

using namespace std;

int nod(int a, int b)
{
    int result = 0;
    if (a > b)
    {
        result = a % b;
        result = result == 0 ? b : nod(b, result);
    }
    else
    {
        result = b % a;
        result = result == 0 ? a : nod(a, result);
    }
    return result;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << nod(a, b) << endl;
    return 0;
}