//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 10/28/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include <string>
#include <vector>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop 
	{
		std::vector<Vehicle*>m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
	};
}