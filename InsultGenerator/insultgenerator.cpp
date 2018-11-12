/*
 * insultgenerator.cpp
 * Author: Mike Cruickshank
 */

#include "insultgenerator.h"

FileException::FileException(const string& message) : message(message) {}
string& FileException::what() { return message; }

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message) {}
string& NumInsultsOutOfBounds::what() {return message; }

void InsultGenerator::initialize() {
	srand(time(NULL));
	ifstream file("InsultsSource.txt");

	if (file.is_open()){
		string currentLine;
		while (getline(file, currentLine, '\n') ){
			vector <string> currentLineDiv;
			stringstream ss(currentLine);
			string currentWord;
			while(getline(ss, currentWord, '\t')) {
				currentLineDiv.push_back(currentWord);
			}
			columnOne.push_back(currentLineDiv[0]);
			columnTwo.push_back(currentLineDiv[1]);
			columnThree.push_back(currentLineDiv[2]);
		}

		file.close();
	} else {
		throw FileException("File cannot be opened.");
	}

} // end initialize method


string InsultGenerator::talkToMe() {
	string newInsult;
	newInsult = "Thou " + columnOne[rand() % 50] +  " " + columnTwo[rand() % 50] + " " + columnThree[rand() % 50] + "!";
	 return newInsult;

} // end talkToMe method


vector <string> InsultGenerator::generate(const int& numberOfInsults) {
	if (numberOfInsults > 10000){
		throw NumInsultsOutOfBounds("Number of Insults is Greater Than 10 000");

	}
	else if (numberOfInsults < 1){
		throw NumInsultsOutOfBounds("Number of Insults is Less Than 1");

	}
	else{
		string tempString;
		set <string> sortedInsults;
		vector <string> listOfInsults;
		pair<set<string>::iterator, bool> ret;
		for (int i = 0; i < numberOfInsults; ++i) {
			 tempString = talkToMe();
			 ret = sortedInsults.insert(tempString);
			 bool isUnique = ret.second;
			 while (!isUnique){
				 ret = sortedInsults.insert(talkToMe());
				 isUnique = ret.second;
			}
		}
		listOfInsults.assign(sortedInsults.begin(), sortedInsults.end());
		return listOfInsults;
	}
}

void InsultGenerator::generateAndSave(const string& outputFileName, const int& numberOfInsults){
	const vector<string> insults = generate(numberOfInsults);
	ofstream file(outputFileName);
	if (file.is_open()){
		 for (int i = 0; i < numberOfInsults; ++ i){
			  file << insults[i] << endl;;
		  }
		 file.close();
		 }
	 else {
		throw FileException("File cannot be opened.");
	 }


} // end generateAndSave method



