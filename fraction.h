#pragma once
#include<iostream>
class fraction
{
private:
	long numerator;
	long denominator;
	void set();
public:
	fraction(long = 0, long = 1);
	long EuclidsAlgorithm(long numerator, long denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
		numerator = abs(numerator);
		while (numerator && denominator) {
			if (numerator > denominator) {
				numerator %= denominator;
			}
			else {
				denominator %= numerator;
			}
		}
		return numerator + denominator;
	}
	long GetNumerator();
	void SetNumerator(long);
	long GetDenominator();
	void SetDenominator(long);
	void check();
	double getDouble();
	void Print()
	{
		if (denominator==0)
		{
			std::cout << std::endl;
		}
		else if(numerator==0)
		{
			std::cout << 0;
		}
		else
		{
		std::cout << numerator << "/" << denominator;

		}
	}
	friend fraction operator+(const fraction& firsfraction, const fraction& secondfraction);
	friend fraction operator-(const fraction& firsfraction, const fraction& secondfraction);
	friend fraction operator*(const fraction& firsfraction, const fraction& secondfraction);
	friend fraction operator/(const fraction& firsfraction, const fraction& secondfraction);
	friend bool operator==(fraction& firsfraction, fraction& secondfraction);
	friend bool operator!=(fraction& firsfraction, fraction& secondfraction);
	friend bool operator>(fraction& firsfraction,  fraction& secondfraction);
	friend bool operator>=(fraction& firsfraction, fraction& secondfraction);
	friend bool operator<(fraction& firsfraction,  fraction& secondfraction);
	friend bool operator<=(fraction& firsfraction, fraction& secondfraction);

};

