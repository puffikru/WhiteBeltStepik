#include <iostream>
#include <vector>

using namespace std;

void toBinary(vector<int>& binary, int num)
{
    if (num >= 1)
    {
        binary.push_back(num % 2);
        toBinary(binary, num / 2);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> binary;
    toBinary(binary, N);
    for (int i = binary.size() - 1; i >=0; --i)
    {
        cout << binary[i];
    }

    return 0;
}