//
// Created by Arias Arevalo, Carlos on 4/22/20.
//

#include "squareRec.h"
#include "rectangle.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;


squareRec::squareRec(double length) : Rectangle(length, length)
{
}

string squareRec::ToString() const {
	stringstream retVal;
	retVal << "{Square " << Rectangle::ToString() << "}";
	return retVal.str();
}
