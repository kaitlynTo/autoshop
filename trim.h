//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 10/28/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace sdds
{
	inline string& trim(string& s)
	{
		//left side trimming
		while (s.length() > 0 && s[0] == ' ')
		{
			//if string exists and the first character is white space
			s.erase(0, 1); //erase the whitespace
		}
		//right side trimming
		while (s.length() > 0 && s[s.length() - 1] == ' ')
		{
			//if string exists and the last character is white space
			s.erase(s.length() - 1, 1);
		}
		return s;
	}
}