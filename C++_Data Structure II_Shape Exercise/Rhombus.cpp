

#include "Rhombus.h"
#include <cmath>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Rhombus::Rhombus(double firstDiagonal, double secondDiagonal) : _firstDiagonal( firstDiagonal), _secondDiagonal(secondDiagonal){
}

string Rhombus::ToString() const {
    stringstream retVal;
    retVal << "{Rhombus " << Shape::ToString() << "first diagonal: " << _firstDiagonal << ", second diagonal: " << _secondDiagonal << "}";
    return retVal.str();
}

double Rhombus::Area() const {
    return _firstDiagonal * _secondDiagonal/2;
}

double Rhombus::Perimeter() const {
    return 2*sqrt(pow(_firstDiagonal,2)+pow(_secondDiagonal,2));
}
