#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

#include <string>
using std::string;

class Rectangle{
	size_t _height, _width;
	Point _upperLeft;
public:
	Rectangle(const Point& upperLeft, size_t width, size_t height);
	~Rectangle();
	size_t Area()const;
	size_t Perimeter()const;
	string ToString()const;
	void Double();

};


#endif
