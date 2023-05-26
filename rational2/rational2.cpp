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

bool operator==(const Rational& lhs, const Rational& rhs)
{
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    int num = 0;
    int den = 1;
    if (lhs.Denominator() == rhs.Denominator())
    {
        num = lhs.Numerator() + rhs.Numerator();
        den = lhs.Denominator();
    }
    else
    {
        num = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
        den = lhs.Denominator() * rhs.Denominator();
    }
    return Rational(num, den);
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    int num = 0;
    int den = 1;
    if (lhs.Denominator() == rhs.Denominator())
    {
        num = lhs.Numerator() - rhs.Numerator();
        den = lhs.Denominator();
    }
    else
    {
        num = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
        den = lhs.Denominator() * rhs.Denominator();
    }
    return Rational(num, den);
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;

    return 0;
}
