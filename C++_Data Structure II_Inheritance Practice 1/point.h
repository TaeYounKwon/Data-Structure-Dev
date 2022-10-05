//
// Created by Arias Arevalo, Carlos on 4/10/20.
//

#ifndef INHERITANCE_EXAMPLE_1_POINT_H
#define INHERITANCE_EXAMPLE_1_POINT_H

#include <string>
using std::string;

class Point {
    double _x, _y;
public:
    Point();
    Point(double x, double y);
    string ToString()const;
    double Distance(const Point& point)const;
    double GetX()const;
    double GetY()const;
};


#endif //INHERITANCE_EXAMPLE_1_POINT_H
