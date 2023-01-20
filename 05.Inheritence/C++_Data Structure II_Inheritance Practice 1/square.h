#ifndef SQUARE_H
#define SQUARE_H

#include "point.h"
#include "rectangle.h"

#include <string>
using std::string;

class Square : public Rectangle{

public:
	Square(const Point& upperLeft, size_t side);
	~Square();
	string ToString()const;
};


#endif
