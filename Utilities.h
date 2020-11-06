//Student Name: Juyoung Park
//Student Number: 150155182
//Student Email: jpark214@myseneca.ca
//Date: 10/28/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include "Car.h"
#include "Racecar.h"
using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}
