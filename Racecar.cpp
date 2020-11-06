//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 11/1/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <sstream>
#include <iostream>
#include <string>
#include "Racecar.h"
#include "trim.h"
using namespace std;

namespace sdds 
{
	Racecar::Racecar(std::istream& in) : Car(in) 
	{
		//extract Car information first
		//take the rest of in for m_booster
		char delim;
		in >> delim >> m_booster;
	}
	void Racecar::display(std::ostream& out)const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed()const 
	{
		return Car::topSpeed() * (m_booster + 1);
	}

}
