//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 10/28/2020
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
		size_t c_topSpeed{ 0 };
	public:
		//custom constructor
		Car(std::istream& in);//a single record of a car information -> read,extract,and store
		std::string condition() const; //returns the condition
		double topSpeed()const; //returns the top_speed
		void display(std::ostream& out)const;//query the vechicle info
	};
}