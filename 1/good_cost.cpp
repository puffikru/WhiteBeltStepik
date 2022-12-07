#include <iostream>

int main()
{
    float N, A, B, X, Y;
    std::cin >> N >> A >> B >> X >> Y;
    if (N > B)
    {
        N *= (1 - Y / 100);
    }
    else if (N > A)
    {
        N *= (1 - X / 100);
    }
    std::cout << N;
    return 0;
}

// cost = N - (N / 100 * Y);