#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>
#include <type_traits>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>

using namespace std;

class Rational {
public:
    Rational() : num(0), den(1) { }

    Rational(int numerator, int denominator) : num(numerator), den(denominator) {
        change();
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return den;
    }
    static int gcd(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b) {
                a = a % b;
            } else {
                b = b % a;
            }
        }
        return a + b;
    }
private:
    int num;
    int den;
    void change() {
        if (num == 0) {
            den = 1;
            return;
        }
        if (den < 0) {
            num = -num;
            den = -den;
        }        
        auto g = num < 0 ? gcd(-num, den) : gcd(num, den);
        num = num / g;
        den = den / g;
    }
};

Rational operator+(const Rational& f, const Rational& s) {
    int gcd = Rational::gcd(f.Denominator(), s.Denominator());
    int fg = f.Denominator() / gcd;
    int sg = s.Denominator() / gcd;
    return Rational{f.Numerator()*sg + s.Numerator()*fg, gcd*fg*sg};
}

Rational operator-(const Rational& f, const Rational& s) {
    int gcd = Rational::gcd(f.Denominator(), s.Denominator());
    int fg = f.Denominator() / gcd;
    int sg = s.Denominator() / gcd;
    return Rational{f.Numerator()*sg - s.Numerator()*fg, gcd*fg*sg};
}

bool operator==(const Rational& f, const Rational& s) {
    return f.Numerator() == s.Numerator() && f.Denominator() == s.Denominator();
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
