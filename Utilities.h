//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 10/28/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Car.h"
#include "Vehicle.h"
#include "trim.h"
using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		string str = "";
		string firstCharacter = "";
		in >> str;
		if (!str.empty())
		{
			str = str.substr(0, str.find(","));
			trim(str);
			firstCharacter = str[0];

			if (firstCharacter == "c" || firstCharacter == "C")
			{
				return new Car(in); //new dynamic object created
				                    //must be delete somewhere
			}
			else
			{
				return nullptr;
			}
		}
		return nullptr;
	}
}
