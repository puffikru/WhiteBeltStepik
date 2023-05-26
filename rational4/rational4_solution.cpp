#include <iostream>
#include <algorithm>
#include<set>
#include <map>
#include <string>
#include<sstream>

using namespace std;

class Rational {
public:
	Rational();
	Rational(int numerator, int denominator);

	int Numerator() const;
	int Denominator() const;
	void Set(const int& n, const int&d);

private:
	void Update();
	int nmr;
	int dnr;
};

Rational::Rational() {
	nmr = 0; dnr = 1;
}
Rational::Rational(int p, int q) {
	nmr = p; dnr = q;
	Update();
}
int Rational::Numerator() const {
	return nmr;
}
void Rational::Set(const int& n, const int&d) {
	nmr = n; dnr = d;
	Update();
}
int Rational::Denominator() const {
	return dnr;
}

void Rational::Update() {
	int p, q;
	p = nmr; q = dnr;
	int sign = 0;
	if ((p < 0 && q>0) || (p > 0 && q < 0))sign = -1;
	else sign = 1;
	p = abs(p); q = abs(q);
	if (q == 0) {}
	else if (p == 0) { p = 0; q = 1; }
	else if (p%q == 0) { p /= q; q = 1; }
	else {
		int mcd = 1;
		for (int i = 1; i <= min(p, q); i++) {
			if (p%i == 0 && q%i == 0)mcd = i;
		}
		p /= mcd; q /= mcd;
	}
	p *= sign;
	nmr = p; dnr = q;
}

Rational operator+ (const Rational& lhr, const Rational& rhr) {
	int numer, denom;
	if (lhr.Denominator() == rhr.Denominator()) { denom = lhr.Denominator(); numer = lhr.Numerator() + rhr.Numerator(); }
	else { denom = lhr.Denominator()*rhr.Denominator(); numer = lhr.Numerator()*rhr.Denominator() + rhr.Numerator()*lhr.Denominator(); }
	return { numer,denom };
}

ostream& operator<< (ostream& outp, const Rational& rat) {
	outp << rat.Numerator() << "/" << rat.Denominator();
	return outp;
}

Rational operator- (const Rational& lhr, const Rational& rhr) {
	int numer, denom;
	if (lhr.Denominator() == rhr.Denominator()) { denom = lhr.Denominator(); numer = lhr.Numerator() - rhr.Numerator(); }
	else { denom = lhr.Denominator()*rhr.Denominator(); numer = lhr.Numerator()*rhr.Denominator() - rhr.Numerator()*lhr.Denominator(); }
	return { numer,denom };
}
bool operator== (const Rational& lhr, const Rational& rhr) {
	return (lhr.Numerator() == rhr.Numerator() && lhr.Denominator() == rhr.Denominator());
}
Rational operator* (const Rational& lhr, const Rational& rhr) {
	int numer, denom;
	numer = lhr.Numerator()*rhr.Numerator(); denom = lhr.Denominator()*rhr.Denominator();
	return { numer,denom };
}
Rational operator/ (const Rational& lhr, const Rational& rhr) {
	int numer, denom;
	numer = lhr.Numerator()*rhr.Denominator(); denom = lhr.Denominator()*rhr.Numerator();
	return { numer,denom };
}


bool operator< (const Rational& lhr, const Rational&rhr) {
	return(lhr.Numerator()*rhr.Denominator() < rhr.Numerator()*lhr.Denominator());
}
void skip2dig(istream& s) {
	char c;
	while (s) {
		c = s.peek();
		if (c == EOF)return;
		if (isdigit(c) || c == '-' || c == '+')return;
		else c = s.get();
	}

}

istream& operator>> (istream& inp, Rational& rat) {
	int n, d; int c; bool flt = false;

	skip2dig(inp);
	if (inp.peek() == EOF) { return inp; }
	if (inp) {
		inp >> n;
		c = inp.get();
		//inp.ignore(1);
		inp >> d;
		if (!inp.fail() && c == '/')rat = Rational(n, d);
	};
	return inp;
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
	{
		const string test{ "5/7 10/8 1/2 -1/3 4/6" };
		const string expected{ "5/7 5/4 1/2 -1/3 2/3 " };
		istringstream input(test);
		ostringstream output;
		Rational r;
		while (input >> r) output << r << ' ';
		if (expected == output.str()) cout << "Goog job!\n";
		else cout << "Wrong format output!\n";


	}
	cout << "OK" << endl;


	return 0;
}