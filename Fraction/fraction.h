/*
 * 		fraction.h
 *
 *  	Created on: Oct 3, 2018
 *      Author: Mike Cruickshank
 */


#pragma once

#include <iostream>
#include <stdlib.h>


using namespace std;

class FractionException{ 		// throws an exception if denominator is zero
public:
	FractionException(const string& msg);
	string& what();
private:
	string msg;
}; // end FileException


class Fraction{

private:
	int numer;
	int denom;
	int GCD(int n, int m);					// returns the greatest common divisor of n and m
	void ReduceFraction(Fraction &fr);		// reduces a fraction to its fundamental form

public:
	Fraction(int i1 = 0, int i2 = 1);      // constructor for Fraction, handles zero, one, or two inputs

	const int& numerator() const;
	const int& denominator() const;

	friend ostream& operator<<(ostream& os, const Fraction& fr);  // overloads << operator for Fraction class
	friend istream& operator>>(istream &is, Fraction &fraction); // overloads >> operator for Fraction class

	Fraction& operator += (Fraction const &rhs);

	// Unary Operators
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator - ();

};

// Non-member functions to overload binary operators
bool operator < (Fraction const &lhs, Fraction const &rhs);
bool operator <= (Fraction const &lhs, Fraction const &rhs);
bool operator > (Fraction const &lhs, Fraction const &rhs);
bool operator >= (Fraction const &lhs, Fraction const &rhs);
bool operator == (Fraction const &lhs, Fraction const &rhs);
bool operator != (Fraction const &lhs, Fraction const &rhs) ;

Fraction operator + (Fraction const &lhs, Fraction const &rhs);
Fraction operator - (Fraction const &lhs, Fraction const &rhs);
Fraction operator * (Fraction const &lhs, Fraction const &rhs);
Fraction operator / (Fraction const &lhs, Fraction const &rhs);
