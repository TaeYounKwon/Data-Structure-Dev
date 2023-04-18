//
// Created by Arias Arevalo, Carlos on 4/22/20.
//

#include "squareRhom.h"
#include "Rhombus.h"
#include <cmath>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;


squareRhom::squareRhom(double length) : Rhombus(length*sqrt(2), length*sqrt(2))
{
}

string squareRhom::ToString() const {
    stringstream retVal;
    retVal << "{Square " << Rhombus::ToString() << "}";
    return retVal.str();
}
