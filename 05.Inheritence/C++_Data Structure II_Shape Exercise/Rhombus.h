//
// Created by Arias Arevalo, Carlos on 4/22/20.
//

#ifndef SHAPES_EXAMPLE_1_RHOMBUS_H
#define SHAPES_EXAMPLE_1_RHOMBUS_H

#include "shape.h"
#include <string>
using std::string;

class Rhombus :  public Shape{
    double _firstDiagonal, _secondDiagonal;
public:
    Rhombus(double firstDiagonal, double secondDiagonal);
    virtual string ToString()const;
    virtual double Area()const;
    virtual double Perimeter()const;
};


#endif //SHAPES_EXAMPLE_1_RHOMBUS_H
