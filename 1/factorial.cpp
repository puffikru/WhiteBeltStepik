#include <iostream>

using namespace std;

int Factorial(int n)
{
    if (n < 0) return 1;
    int result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

//int main()
//{
//    int N;
//    cin >> N;
//    if (N < 0)
//    {
//        cout << 1 << endl;
//    }
//    else
//    {
//        cout << Factorial(N) << endl;
//    }
//    return 0;
//}