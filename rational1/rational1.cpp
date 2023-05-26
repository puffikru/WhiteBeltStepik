#include <iostream>
#include <numeric>

using namespace std;

class Rational
{
public:
    Rational()
    {
        _numerator = 0;
        _denominator = 1;
    }

    Rational(int numerator, int denominator)
    {
        int nod = gcd(numerator, denominator);
        if (numerator == 0)
        {
            _numerator = numerator;
            _denominator = 1;
        }
        else if (denominator < 0)
        {
            _numerator = numerator / nod * -1;
            _denominator = denominator / nod * -1;
        }
        else
        {
            _numerator = numerator / nod;
            _denominator = denominator / nod;
        }
    }

    int Numerator() const
    {
        return _numerator;
    }

    int Denominator() const
    {
        return _denominator;
    }

private:
    int _numerator;
    int _denominator;
};

int main()
{
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10)
        {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3)
        {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3)
        {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3)
        {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1)
        {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1)
        {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;

    return 0;
}
