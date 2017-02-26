#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
		counter = 0;
	}

	// destructor
	~MedicalRecord() {
		delete[] ptr;
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);
		while (!myfile.eof())
		{
			++numOfBabies;
		}
		ptr = new Baby[numOfBabies];
		myfile.clear();
		myfile.seekg(0, ios::beg);

		if (myfile.is_open()) 
		{
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
				// cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName(string s) {
		return "COMPLETE ME"; // TO BE COMPLETED
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return numOfBabies;
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
		return -1; 
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
		return -1; 
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {
		ptr[counter] = b;
		counter++;
	}
	
	int numOfBabies;
	Baby* ptr; 
	int counter;

	// Add private member variables for your data structuraalong with any 
	// other variables required to implement the public member functions

};
