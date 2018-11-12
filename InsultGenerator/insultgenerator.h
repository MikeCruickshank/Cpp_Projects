/*
 * insultgenerator.h
 * Author: Mike Cruickshank
 */


#pragma once


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <set>
#include <iterator>
#include <numeric>
#include <stdexcept>
#include <time.h>

using namespace std;

class FileException{ 		// throws an exception if the file cannot be read or opened or written to
public:
	FileException(const string& message);
	string& what();
private:
	string message;
}; // end FileException


class NumInsultsOutOfBounds{  		// throws an exceptions if the number of insults is < 1 or > 10 000
public:
	NumInsultsOutOfBounds(const string& message);
	string& what();
private:
	string message;
}; // end NumInsultsOutOfBounds


class InsultGenerator{
	private:
		vector <string> columnOne, columnTwo, columnThree;

	public:
		void initialize();					// initialize the columns containing insults
		string talkToMe();					// generates one random insult
		vector <string> generate(const int& numberOfInsults);	 // generates random, unique insults in alphabetical order
		void generateAndSave(const string& outputFileName, const int& numberOfInsults);   // saves a list of insults to a file
}; // end class InsultGenerator


