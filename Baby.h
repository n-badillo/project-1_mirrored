#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby() { 
		name = "";
		weight = 0;// default constructor
	};

	Baby(string s, int w) 
	{ // constructor
		
		name = s;
		weight = w; 
							
	}
	Baby(const Baby& x) 
	{ // copy constructor
		name = x.name;
		weight = x.weight;
	}
	Baby& operator = (const Baby x)
	{
		if (this != &x)
		{
			name = x.name;
			weight = x.weight;
		}
	}

	// a "getter" method
	int getWeight() {

		return weight;
	}

	// a "getter" method
	string getName() {
		return name; 
	}

private:
	
	string name;
	int weight;
	friend class Medicalrecord;
};
