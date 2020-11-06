//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 11/5/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Utilities.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		string record{};
		getline(in, record, '\n'); //getline from istream and store to record
		stringstream ss(record);  //create new stream containing 'record'
		char firstCharacter = '\0';
		char delim = '\0';
		ss >> firstCharacter >> delim; // get firstCharacter and delimiter

		if (ss)
		{
			if (firstCharacter == 'c' || firstCharacter == 'C')
			{
				return new Car(ss); //passing left stream
			}
			else if (firstCharacter == 'r' || firstCharacter == 'R')
			{
				return new Racecar(ss);
			}
			else
			{
				throw firstCharacter;
			}
		}
		else
		{
			return nullptr;
		}
	}
}