#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> numbers;

    for (int i = 0; i < N; ++i)
    {
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    sort(begin(numbers), end(numbers), [](int a, int b){
        return abs(a) < abs(b);
    });

    for (const auto& n : numbers)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}