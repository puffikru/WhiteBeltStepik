#include <iostream>
#include <numeric>
#include <sstream>

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

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

ostream& operator<<(ostream& os, const Rational& rat)
{
    os << rat.Numerator() << "/" << rat.Denominator();
    return os;
}

istream& operator>>(istream& is, Rational& rat)
{
    int num, den;
    char c;
    if (is)
    {
        is >> num >> c >> den;
        if (is && c == '/')
        {
            rat = Rational(num, den);
        }
    }
    return is;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
