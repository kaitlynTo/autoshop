//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 11/05/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <sstream>
#include <iomanip>
#include <exception>
#include "Car.h"
#include "trim.h"
using namespace std;

namespace sdds
{
	//custom constructor - extracting a single car information
	Car::Car(istream& in)
	{
		//in format: MAKER, CONDITION, SPEED

		//MAKER token
		getline(in, maker, ',');
		trim(maker);

		//CONDITION token
		getline(in, c_condition, ',');
		trim(c_condition);
		if (c_condition.empty())
			c_condition = "n"; //when condition is not given, set it to 'n'
		else if (c_condition != "n" && c_condition != "u" && c_condition != "b")
			throw "Invalid record!"; //if condition is neither n,u, or b, throw exception

		//SPEED token
		string strSpeed{};
		getline(in, strSpeed, ',');
		try
		{
			c_topSpeed = stoi(trim(strSpeed));
		}
		catch (...)
		{
			throw "Invalid record!"; //if extracted token is not a number, throw exception
		}
	}

	//returns the condition
	std::string Car::condition() const
	{
		return c_condition;
	}

	//returns the top_speed
	double Car::topSpeed()const
	{
		return c_topSpeed;
	}

	//query the vechicle info
	void Car::display(std::ostream& out)const
	{
		string conditionOutput = "";
		if (c_condition == "n")
			conditionOutput = "new";
		else if (c_condition == "u")
			conditionOutput = "used";
		else if (c_condition == "b")
			conditionOutput = "broken";

		//|MAKER(10)|CONDITION(6)|TOP_SPEED(6(.2))
		out << "| " << setw(10) << maker
			<< " | " << left << setw(6) << conditionOutput
			<< " | " << right << fixed << setw(6) << setprecision(2) << topSpeed() << " |";
		//topSpeed() is polymorphic pointing either Car's or Racecar's.
	}
}