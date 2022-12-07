#include <iostream>

int main()
{
    int A, B;
    std::cin >> A >> B;
    if (B == 0)
    {
        std::cout << "Impossible" << std::endl;
    }
    else
    {
        std::cout << int(A / B) << std::endl;
    }
    return 0;
}
