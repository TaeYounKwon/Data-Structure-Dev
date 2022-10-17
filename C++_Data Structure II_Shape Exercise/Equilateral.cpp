//
// Created by simson-kd on 2021-04-19.
//

#include "Equilateral.h"
#include "isosceles.h"

#include <string>
#include <sstream>
#include <cassert>

using std::string;
using std::stringstream;

Equilateral::Equilateral(double equalSidesLength)
        : Isosceles(equalSidesLength, equalSidesLength) {
}

string Equilateral::ToString() const {
    stringstream retVal;
    retVal << "{Equilateral " << Isosceles::ToString() << "}";
    return retVal.str();
}