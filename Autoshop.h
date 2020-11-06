//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 10/28/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include <string>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop 
	{
		std::vector<Vehicle*>m_vehicles;
	public:
		//destructor
		~Autoshop(); 
		//template function - that iterates over the vehicles
		template<typename T> 
		void select(T test, std::list<const Vehicle*>& vehicles);
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
	};

	//select template function definition 
	template<typename T>
	void Autoshop::select(T test, std::list<const Vehicle*>& vehicles)
	{
		//if 'test'is True,
		//adds the m_vehicles elements to the 'vehicles'(2nd param)
		
		for (auto i = m_vehicles.begin(); i != m_vehicles.end();i++)
		{
			if (test(*i))
			{
				vehicles.push_back(*i);
			}
		}
		
	}
}