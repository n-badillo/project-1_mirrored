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
		string name;
		int weight;
		while (myfile >> name >> weight)
		{
			++numOfBabies;
		}
		ptr = new Baby[numOfBabies];
		myfile.clear();
		myfile.seekg(0, ios::beg);

		if (myfile.is_open()) 
		{
			cout << "Successfully opened file " << filename << endl;
			
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
	string mostPopularName() {
		
		numOfMostPopularName = 0;
		numOfOtherName = 0;
		for (int i=0; i < numOfBabies; i++)
		{
			
			for (int j=0; j < numOfBabies; j++)
			{
				if (ptr[i].getName() == ptr[j].getName())
					++numOfOtherName;
			}
			if (numOfOtherName > numOfMostPopularName)
			{
				numOfMostPopularName = numOfOtherName;
				
				mostPopName = ptr[i].getName();

			}
			numOfOtherName = 0;
			
		}
			
		return mostPopName;
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return numOfBabies;
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
		for (int i = 0; i < numOfBabies; i++)
		{
			if (ptr[i].getWeight() < 2500)
				numOfLowWeight++;
			else continue; 
		}
		return numOfLowWeight;
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
		for (int i = 0; i < numOfBabies; i++)
		{
			if (ptr[i].getName() == s)
				sameName++;
			else continue; 
		}
		return sameName; 
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {
		ptr[counter] = b;
		counter++;
	}
	int numOfLowWeight;
	int sameName;
	int numOfBabies;
	Baby* ptr; 
	int counter;
	string mostPopName;
	int numOfMostPopularName;
	int numOfOtherName;
	

	// Add private member variables for your data structuraalong with any 
	// other variables required to implement the public member functions

};
