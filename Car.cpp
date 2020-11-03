//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 10/28/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <exception>
#include "Car.h"
#include "trim.h"
using namespace std;
namespace sdds
{
	//custom constructor - extract a single car information
	Car::Car(istream& in)
	{
		string delim = "";
		string speed = "";
		int delimAt = 0;

		//MAKER token
		in >> maker;
		delimAt = maker.find(",") > 0 ? maker.find(",") : -1;
		if (delimAt > 0)
			maker.erase(delimAt, 1);
		else
			in >> delim;

		//CONDITION token
		in >> c_condition;
		delimAt = c_condition.find(",") >= 0 ? c_condition.find(",") : -1;
		if (delimAt > 0)
			c_condition.erase(delimAt, 1);
		else
			in >> delim;

		if (c_condition.empty() || (c_condition != "n" && c_condition != "u" && c_condition != "b"))
			throw "Invalid record!";

		//SPEED token
		in >> speed;
		try
		{
			c_topSpeed = stoi(speed);
		}
		catch (std::bad_typeid& id)
		{
			cerr<< "Unrecognized record type: [" << id.what() << "]" << endl;
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
		out << "| " << setw(10) << maker << " | "
			<< left << setw(6) << conditionOutput << " | "
			<< right << fixed << setw(6) << setprecision(2) << (double)c_topSpeed << " |"
			<< endl;
	}
}