#include <algorithm>
#include <charconv>
#include <exception>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>

using namespace std;

class Rational {
public:
    Rational()
    {
        numerator = 0;
        denominator = 1;
    }
    Rational(int new_numerator, int new_denominator)
    {
        if (new_denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
        const int gcd = std::gcd(new_numerator, new_denominator);
        numerator = new_numerator / gcd;
        denominator = new_denominator / gcd;
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    int Numerator() const
    {
        return numerator;
    }

    int Denominator() const
    {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

bool operator==(const Rational& lhs, const Rational& rhs)
{
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    return {
        lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    return {
        lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return {
        lhs.Numerator() * rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator>>(istream& is, Rational& r)
{
    int n, d;
    char c;
    is >> n >> c >> d;
    if (is && c == '/') {
        r = Rational(n, d);
    }
    return is;
}

ostream& operator<<(ostream& os, const Rational& r)
{
    return os << r.Numerator() << '/' << r.Denominator();
}

bool operator<(const Rational& lhs, const Rational& rhs)
{
    return (lhs - rhs).Numerator() < 0;
}

void PerformOperation(istream& input)
{
    try {
        Rational num1, num2;
        char oper;
        input >> num1 >> oper >> num2;

        if (oper == '+') {
            cout << num1 + num2;
        } else if (oper == '-') {
            cout << num1 - num2;
        } else if (oper == '*') {
            cout << num1 * num2;
        } else if (oper == '/') {
            cout << num1 / num2;
        }

    } catch (exception const& ex) {
        cout << ex.what();
    }
}

int main()
{
    PerformOperation(cin);
    return 0;
}
