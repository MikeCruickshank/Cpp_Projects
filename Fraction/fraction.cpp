/*
 *  fraction.cpp
 *
 *  Created on: Oct 3, 2018
 *  Author: Mike Cruickshank
 */

#include "fraction.h"

FractionException::FractionException(const string& msg) : msg(msg) {}
string& FractionException::what() {return msg; }

Fraction::Fraction(int n, int d){
	if (d != 0){
		int div = GCD(n,d);
		numer = n/div;
		denom = d/div;

		if (denom < 0){
			numer = -1*numer;
			denom = -1*denom;
		}
	}
	else{
		throw FractionException("Invalid Fraction: Divided By Zero");
	}
}

const int& Fraction::numerator() const{
	return numer;
}

const int& Fraction::denominator() const{
	return denom;
}

int Fraction::GCD(int n, int m){
	m = abs(m); n = abs(n);
	if (m <= n && n % m == 0){
		return m;
	}
	else if (n < m){
		if (n == 0){
			return 1;
		}
		return GCD(m,n);
	}
	else{
		return GCD(m,n % m);
	}

}

void Fraction::ReduceFraction(Fraction &fr){
	 int div = GCD(fr.numer ,fr.denom);
	 fr.numer = fr.numer/div;
	 fr.denom = fr.denom/div;
}

ostream& operator<<(ostream& os, const Fraction& fr)
{
    os << fr.numer << '/' << fr.denom;
    return os;
}

istream& operator>>(istream &is, Fraction &fr){
	string inputFraction;
	is >> inputFraction;
	string number;
	string::iterator ittString = inputFraction.begin();
	bool isDenom = false;
	while (ittString < inputFraction.end()) {
		if (*ittString == '/' && ittString != inputFraction.begin()){
			fr.numer = stoi(number);
			number.clear();
			isDenom = true;
		}
		else {
			number += *ittString;
		}
		++ittString;
	}

	if (isDenom){
		fr.denom = stoi(number);
	} else{
		fr.numer = stoi(number);
	}
	return is;
}



Fraction& Fraction::operator += (Fraction const &rhs) {

    numer = (rhs.denom)*numer + (denom)*rhs.numer;
    denom = (rhs.denom)*denom;

	int div = GCD(numer,denom);
	numer = numer/div;
	denom = denom/div;
	return *this;
}

Fraction& Fraction::operator ++ () {
	numer = numer + denom;
	return *this;
}

Fraction Fraction::operator ++ (int) {
     Fraction res;
     res.numer = numer;
     res.denom = denom;

     numer = numer + denom;


     ReduceFraction(res);
     return res;
}

Fraction& Fraction::operator - () {
	numer = numer - denom;
	return *this;
}

// Non-member functions

bool operator < (Fraction const &lhs, Fraction const &rhs) {

	if (lhs.numerator()*rhs.denominator() < lhs.denominator()*rhs.numerator()){
		return true;
	}
	else{
		return false;
	}
}

bool operator <= (Fraction const &lhs, Fraction const &rhs) {

	if (lhs.numerator()*rhs.denominator() <= lhs.numerator()*rhs.denominator()){
		return true;
	}
	else{
		return false;
	}
}

bool operator > (Fraction const &lhs, Fraction const &rhs) {

	if (lhs.numerator()*rhs.denominator() > lhs.denominator()*rhs.numerator()){
		return true;
	}
	else{
		return false;
	}
}

bool operator >= (Fraction const &lhs, Fraction const &rhs) {

	if (lhs.numerator()*rhs.denominator() >= lhs.denominator()*rhs.numerator()){
		return true;
	}
	else{
		return false;
	}
}

bool operator == (Fraction const &lhs, Fraction const &rhs) {

	if (lhs.numerator()*rhs.denominator() == lhs.denominator()*rhs.numerator()){
		return true;
	}
	else{
		return false;
	}
}

bool operator != (Fraction const &lhs, Fraction const &rhs) {

	if (lhs.numerator()*rhs.denominator() != lhs.denominator()*rhs.numerator()){
		return true;
	}
	else{
		return false;
	}
}


Fraction operator + (Fraction const &lhs, Fraction const &rhs) {
     int numerator = rhs.denominator()*lhs.numerator() + rhs.numerator()*lhs.denominator();
     int denominator = (rhs.denominator()*lhs.denominator());
     return Fraction(numerator, denominator);
}

Fraction operator - (Fraction const &lhs, Fraction const &rhs) {
		 int numerator = rhs.denominator()*lhs.numerator() - lhs.denominator()*rhs.numerator();
		 int denominator = (rhs.denominator())*lhs.denominator();
		 return Fraction(numerator, denominator);
}

Fraction operator * (Fraction const &lhs, Fraction const &rhs){
	int numerator = lhs.numerator()*rhs.numerator();
	int denominator = rhs.denominator()*lhs.denominator();
	return Fraction(numerator, denominator);
}

Fraction operator / (Fraction const &lhs, Fraction const &rhs){
	int numerator = lhs.numerator()*rhs.denominator();
	int denominator = lhs.denominator()*rhs.numerator();
	return Fraction(numerator, denominator);
}
