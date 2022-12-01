#include <iostream>
#include <cmath>

int main()
{
//     Ax² + Bx + C = 0.
    double a, b, c;
    std::cin >> a >> b >> c;
    double D = b * b - (4 * a * c);

    if (a != 0)
    {
        if (D < 0)
        {
            std::cout << "" << std::endl;
        }
        else if (D == 0)
        {
            double x = -b / (2 * a);
            std::cout << x << std::endl;
        }
        else if (D > 0)
        {
            double x1 = (-b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D)) / (2 * a);
            std::cout << x1 << " " << x2 << std::endl;
        }
    }
    else if (a == 0)
    {
        if (b != 0)
        {
            double x = -c / b;
            std::cout << x << std::endl;
        }
        else
        {
            std::cout << "" << std::endl;
        }
    }
    return 0;
}