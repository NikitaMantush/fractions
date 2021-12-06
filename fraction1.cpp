#include "fraction.h"
#include <iostream>
#include <stdexcept>
fraction::fraction(long numerator, long denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
	if (denominator < 0)
	{
		denominator = abs(denominator);
		numerator *= -1;
	}
	if (numerator == 0) {
		denominator = 1;
	}
	long m_gcd = EuclidsAlgorithm(numerator, denominator);
	numerator /= m_gcd;
	denominator /= m_gcd;
}
void fraction::set()
{
	if (denominator < 0)
	{
		denominator = abs(denominator);
		numerator *= -1;
	}
	if (numerator == 0)
	{
		denominator = 1;
	}
	long m_gcd = EuclidsAlgorithm(numerator, denominator);
	numerator /= m_gcd;
	denominator /= m_gcd;
}
double fraction::getDouble()
{
	return static_cast<double>(numerator) / denominator;
}
void fraction::SetNumerator(long numerator)
{
	this->numerator=numerator;
	set();
}
long fraction::GetNumerator()
{
	return numerator;
}
void fraction::SetDenominator(long denominator)
{
	this->denominator = denominator;
	set();
}
long fraction::GetDenominator()
{
	return denominator;
}
void fraction::check() {
	if (denominator == 0) {
		throw std::overflow_error("denominator is zero");
	}
}
fraction operator+(const fraction& firsfraction, const fraction& secondfraction)
{
	long num1;
	long denom1;
	num1 = firsfraction.numerator*secondfraction.denominator + secondfraction.numerator*firsfraction.denominator;
	denom1 = firsfraction.denominator * secondfraction.denominator;
	fraction temp(num1, denom1);
	temp.set();
	return temp;
 }
fraction operator-(const fraction& firsfraction, const fraction& secondfraction)
{
	long num1;
	long denom1;
	num1 = firsfraction.numerator * secondfraction.denominator - secondfraction.numerator * firsfraction.denominator;
	denom1 = firsfraction.denominator * secondfraction.denominator;
	fraction temp(num1, denom1);
	temp.set();
	return temp;
}
fraction operator *(const fraction& firsfraction, const fraction& secondfraction)
{
	long num1;
	long denom1;
	num1 = firsfraction.numerator * secondfraction.numerator;
	denom1 = firsfraction.denominator * secondfraction.denominator;
	fraction temp(num1, denom1);
	temp.set();
	return temp;
}
fraction operator /(const fraction& firsfraction, const fraction& secondfraction)
{
	fraction temp(0,0);
	if (secondfraction.numerator != 0) 
	{
		long denom1 = firsfraction.numerator * secondfraction.denominator;
		long num1 = firsfraction.denominator * secondfraction.numerator;
		fraction temp(num1, denom1);
		temp.set();
		return temp;
	}
	else
	{
		std::cout << "Error";
		temp.numerator = 0;
		temp.denominator = 0;
		return temp;
	}
}
 bool operator== (fraction& firsfraction, fraction& secondfraction) 
 {
	 if (firsfraction.getDouble() == secondfraction.getDouble())
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
		
}
 bool operator!= (fraction& firsfraction, fraction& secondfraction)
 {
	 if (firsfraction.getDouble() != secondfraction.getDouble())
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }

 }
 bool operator>  (fraction& firsfraction, fraction& secondfraction)
 {
	 if (firsfraction.getDouble() > secondfraction.getDouble())
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }

 }
 bool operator>= (fraction& firsfraction, fraction& secondfraction)
 {
	 if (firsfraction.getDouble() >= secondfraction.getDouble())
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }

 }
 bool operator<  (fraction& firsfraction, fraction& secondfraction)
 {
	 if (firsfraction.getDouble() < secondfraction.getDouble())
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }

 }
 bool operator<= (fraction& firsfraction, fraction& secondfraction)
 {
	 if (firsfraction.getDouble() <= secondfraction.getDouble())
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }

 }
