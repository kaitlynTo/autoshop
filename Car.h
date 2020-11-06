//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 11/5/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#pragma once
#include <string>
#include "Vehicle.h"
namespace sdds
{
	//a single car information
	class Car : public Vehicle
	{
		std::string maker{};
		std::string c_condition{};
		double c_topSpeed{ 0 };
	public:

		Car(std::istream& in); //custom constructor
		std::string condition() const; //returns the condition
		double topSpeed()const; //returns the top_speed
		void display(std::ostream& out)const;//query the vechicle info
	};
}