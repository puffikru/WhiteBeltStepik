#include <iostream>
#include <numeric>
#include <sstream>
#include <set>
#include <map>

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
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
