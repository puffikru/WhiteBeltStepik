//#include <iostream>
//#include<set>
//#include<map>
//#include<string>
//#include<sstream>
//
//using namespace std;
//
//int GreatestCommonDivisor(int a, int b) {
//	if (b == 0) {
//		return a;
//	}
//	else {
//		return GreatestCommonDivisor(b, a % b);
//	}
//}
//
//class Rational {
//public:
//	Rational() {  
//		numerator = 0;
//		denominator = 1;
//	}
//	Rational(int new_numerator, int new_denominator) {
//		const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
//		numerator = new_numerator / gcd;
//		denominator = new_denominator / gcd;
//		if (denominator < 0) {
//			denominator = -denominator;
//			numerator = -numerator;
//		}
//	}
//
//	int Numerator() const {
//		return numerator;
//	}
//
//	int Denominator() const {
//		return denominator;
//	}
//
//private:
//	int numerator;
//	int denominator;
//};
//
//bool operator == (const Rational& lhs, const Rational& rhs) {
//	return lhs.Numerator() == rhs.Numerator() &&
//		lhs.Denominator() == rhs.Denominator();
//}
//
//Rational operator + (const Rational& lhs, const Rational& rhs) {
//	return {
//		lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
//		lhs.Denominator() * rhs.Denominator()
//	};
//}
//
//Rational operator - (const Rational& lhs, const Rational& rhs) {
//	return {
//		lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
//		lhs.Denominator() * rhs.Denominator()
//	};
//}
//
//Rational operator * (const Rational& lhs, const Rational& rhs) {
//	return {
//		lhs.Numerator() * rhs.Numerator(),
//		lhs.Denominator() * rhs.Denominator()
//	};
//}
//
//Rational operator / (const Rational& lhs, const Rational& rhs) {
//	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
//}
//
//istream& operator >> (istream& is, Rational& r) {
//	int n, d;
//	char c;
//	is >> n >> c >> d;
//	if (is && c == '/') {
//		r = Rational(n, d);
//	}
//	return is;
//}
//
//ostream& operator << (ostream& os, const Rational& r) {
//	return os << r.Numerator() << '/' << r.Denominator();
//}
//
//bool operator < (const Rational& lhs, const Rational& rhs) {
//	return (lhs - rhs).Numerator() < 0;
//}


#include <iostream> 
#include <fstream> 
#include <iomanip> 
#include <string> 
#include <vector> 
#include <sstream> 
using namespace std;
int NOD(long int a, long int b) {
	while (a > 0 && b > 0) {

		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}

	}
	return a + b;
}

class Rational {
public:
	Rational() {
		u = 0;
		d = 1;
	}
	Rational(long int a, long int b) {
		if (a == 0) {
			u = 0;
			d = 1;
		}
		else {
			int nod = NOD(abs(a), abs(b));
			u = a / nod;
			d = b / nod;
			if (d < 0) {
				d -= d * 2;
				u -= u * 2;
			}
		}
	}

	int Numerator() const {
		return u;
	}

	int Denominator() const {
		return d;
	}
private:
	long int u;
	long int d;
};

Rational operator+(const Rational& a, const Rational& b) {
	Rational c(a.Numerator() * b.Denominator() + b.Numerator()*a.Denominator(), b.Denominator()*a.Denominator());
	return c;
}
Rational operator-(const Rational& a, const Rational& b) {
	Rational c(a.Numerator() * b.Denominator() - b.Numerator()*a.Denominator(), b.Denominator()*a.Denominator());
	return c;
}
Rational operator/(const Rational& a, const Rational& b) {
	Rational c(a.Numerator() * b.Denominator(), a.Denominator()*b.Numerator());
	return c;
}
Rational operator*(const Rational& a, const Rational& b) {
	Rational c(a.Numerator() * b.Numerator(), b.Denominator()*a.Denominator());
	return c;
}
bool operator==(const Rational& a, const Rational& b) {
	Rational c;
	if ((a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator())) {
		return true;
	}
	else {
		return false;
	}
}



//ostream& operator << (ostream& os, const Rational& r) {
//	return os << r.Numerator() << '/' << r.Denominator();
//}
//
//bool operator < (const Rational& lhs, const Rational& rhs) {
//	return (lhs - rhs).Numerator() < 0;
//}
//
//#include<map>
//#include<set>

//void test() {
//
//	Rational r(4, 6);
//	cout << r <<" simply Rational must equel 2/3\n";
//	const Rational sum = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
//	cout << sum << " sum Rational must equel 7/12\n";
//	const Rational multy = Rational(1, 2) * Rational(1, 3) / Rational(1, 4);
//	cout << multy << " product Rational must equel 2/3\n";
//
//	set<Rational> rationals;
//	rationals.insert(Rational(1, 2));
//	rationals.insert(Rational(1, 3));
//	cout << "set Rational\n";
//	for (const auto& s : rationals) {
//		cout << s << '\n';
//	}
//
//	map<Rational, string> name;
//	name[Rational(1, 2)] = "one half";
//	cout << "map Rational\n";
//	for (const auto&m : name) {
//		cout << m.first << " is " << m.second << '\n';
//	}
//
//
//}

int main() {
	//test();

	return 0;
}