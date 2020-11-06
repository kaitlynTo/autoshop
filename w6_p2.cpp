//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 11/05/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Autoshop.h"
#include "Autoshop.h"
#include "Utilities.h"
#include "Utilities.h"


void loadData(const char* filename, sdds::Autoshop& as)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
		return;
	}
	while (file)
	{
		// TODO: This code can throw errors to signal that something went wrong while
		//         extracting data. Write code to catch and handle the following errors:
		//       - the type of vehicle is not recognized: the first non-empty character
		//           on the line is not 'c', 'C', 'r', or 'R'. In this case print
		//           "Unrecognized record type: [TAG]<endl>"
		//       - one of the fields in the record contains invalid data. In this case print
		//           "Invalid record!<endl>"
		try
		{
			sdds::Vehicle* aVehicle = sdds::createInstance(file);
			if (aVehicle)
				as += aVehicle;
		}
		catch (const char* msg)
		{
			cout << msg << endl;  //print out "Invalid record!"
		}
		catch (const char c)
		{
			cout << "Unrecognized record type: [" << c << "]" << endl;
		}
	}
}

// ws dataClean.txt dataMessy.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::Autoshop as;
	loadData(argv[1], as);
	as.display(std::cout);
	std::cout << "\n";
	loadData(argv[2], as);
	as.display(std::cout);

	std::cout << std::endl;
	std::list<const sdds::Vehicle*> vehicles;
	{
		// TODO: Create a lambda expression that receives as parameter `const sdds::Vehicle*`
		//         and returns true if the vehicle has a top speed >300km/h
		auto fastVehicles = [](const sdds::Vehicle* v) { return v->topSpeed() > 300; };
		as.select(fastVehicles, vehicles); //only storing fast vehicles to the 'vehicles' list
		std::cout << "--------------------------------\n";
		std::cout << "|       Fast Vehicles          |\n";
		std::cout << "--------------------------------\n";
		for (auto it = vehicles.begin(); it != vehicles.end(); ++it)
		{
			//iterating over vehicles list
			(*it)->display(std::cout); //display every vehicle in the list
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}

	vehicles.clear(); //destroys the list by removing all elements from the list and sets size of list to zero
	std::cout << std::endl;
	{
		// TODO: Create a lambda expression that receives as parameter `const sdds::Vehicle*`
		//         and returns true if the vehicle is broken and needs repairs.
		auto brokenVehicles = [](const sdds::Vehicle* v) { return v->condition() == "b"; };
		as.select(brokenVehicles, vehicles); //storing only broken vehicles into the vehicles list
		std::cout << "--------------------------------\n";
		std::cout << "| Vehicles in need of repair   |\n";
		std::cout << "--------------------------------\n";
		for (const auto vehicle : vehicles)
		{
			//iterating over vehicles list
			vehicle->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}

	return 0;
}
