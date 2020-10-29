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
	//string trim spaces
	inline string& ltrim(string& s)
	{
		//trim whitespaces until it's not whitespace from left hand side
		for (size_t i = 0; i < s.length() && s[i] == ' '; i++)
		{
			if (isspace(s[i]))
			{
				s.erase(i, 1);
				i--;
			}
		}
		//return the trimmed token
		return s;
	}
	inline string& rtrim(string& s)
	{
		//trim whitespaces until it's not whitespace
		for (size_t i = s.length() - 1; i >= 0 && s[i] == ' '; i--)
		{
			if (isspace(s[i]))
			{
				s.erase(i, 1);
			}
		}
		//return the trimmed token
		return s;
	}
	inline string& trim(string& s)
	{
		ltrim(s);
		rtrim(s);
		return s;
	}
}