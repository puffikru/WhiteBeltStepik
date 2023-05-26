#include <iostream>
#include <numeric>
#include <sstream>
#include <set>
#include <map>
#include <exception>

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
        else if (denominator == 0)
        {
            throw invalid_argument("devision by zero");
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
    if (lhs.Denominator() * rhs.Numerator() == 0) throw domain_error("division by zero");
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

bool operator<(const Rational& lhs, const Rational& rhs)
{
    if (lhs.Denominator() == rhs.Denominator())
    {
        return lhs.Numerator() < rhs.Numerator();
    }
    else
    {
        if (lhs.Numerator() == rhs.Numerator())
        {
            return lhs.Denominator() > rhs.Denominator();
        }
        return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
    }
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
