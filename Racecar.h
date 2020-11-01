//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 11/1/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster{ 0.0 }; //percentages (0-1)
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out)const;
		double topSpeed()const;
	};
}