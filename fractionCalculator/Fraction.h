#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Fraction {
	public:

	int m_nume, m_denom, m_whole;
	bool m_sign;

	Fraction();

	Fraction(bool negFlag, int whole, int numerator, int denominator);

	bool GetSign() const;

	int GetNumerator() const;

	int GetDenominator() const;

	int GetWhole() const;

	const Fraction operator* (const Fraction& rhs) const;

	const Fraction operator/ (const Fraction& rhs) const;

	const Fraction operator+ (const Fraction& rhs) const;

	const Fraction operator- (const Fraction& rhs) const;

	private:
		int numerator,denominator, whole;
		bool negFlag;
		


};

ostream& operator << (ostream& out, const Fraction& number);

#endif