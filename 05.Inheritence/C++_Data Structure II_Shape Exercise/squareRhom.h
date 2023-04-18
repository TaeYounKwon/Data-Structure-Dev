//
// Created by 태윤 on 2021-04-20.
//

#ifndef ELLIPSE_H_SQUARERHOM_H
#define ELLIPSE_H_SQUARERHOM_H

#include "Rhombus.h"
#include <string>
using std::string;

class squareRhom : public Rhombus{
public:
    squareRhom(double length);
    string ToString()const;
};


#endif //ELLIPSE_H_SQUARERHOM_H
