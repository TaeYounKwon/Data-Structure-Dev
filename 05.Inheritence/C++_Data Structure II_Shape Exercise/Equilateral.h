//
// Created by simson-kd on 2021-04-19.
//

#ifndef SHAPES_EXAMPLE_1_EQUILATERAL_H
#define SHAPES_EXAMPLE_1_EQUILATERAL_H
#include "isosceles.h"

class Equilateral : public Isosceles {
public:
    Equilateral(double equalSidesLength);
    virtual string ToString()const;
};

#endif //SHAPES_EXAMPLE_1_EQUILATERAL_H
