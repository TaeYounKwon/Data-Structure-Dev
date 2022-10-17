//
// Created by Arias Arevalo, Carlos on 4/22/20.
//

#ifndef SHAPES_EXAMPLE_1_SQUAREREC_H
#define SHAPES_EXAMPLE_1_SQUAREREC_H

#include "rectangle.h"
#include <string>
using std::string;

class squareRec : public Rectangle{
public:
    squareRec(double length);
	string ToString()const;
};



#endif //SHAPES_EXAMPLE_1_SQUAREREC_H
