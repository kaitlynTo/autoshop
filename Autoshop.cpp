//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 10/28/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <string>
#include <sstream>
#include "Autoshop.h"
using namespace std;

namespace sdds
{
	Autoshop::~Autoshop()
	{
		for (auto& vehicle : m_vehicles)
		{
			delete vehicle;
		}
	}
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);

		return *this;
	}

	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;

		for (unsigned i = 0; i < m_vehicles.size(); i++)
		{
			m_vehicles[i]->display(out);
		}
		out << "--------------------------------" << endl;
	}

}