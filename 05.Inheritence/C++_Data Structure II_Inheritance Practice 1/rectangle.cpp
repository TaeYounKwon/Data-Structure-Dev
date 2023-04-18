#include "rectangle.h"

#include <sstream>
#include <string>
using std::string;
using std::stringstream;

#include <iostream>
using std::cout;
using std::endl;

Rectangle::Rectangle(const Point& upperLeft, size_t width, size_t height) : _height(height), _width(width), _upperLeft(upperLeft){
	cout << "\tRectangle::Rectangle(" << _width << ", " << _height << ")" << endl;
}
Rectangle::~Rectangle(){
	cout << "\tRectangle::~Rectangle(" << _width << ", " << _height << ")" << endl;
}
size_t Rectangle::Area()const{
	return _width * _height;
}
size_t Rectangle::Perimeter()const{
	return 2 * _width + 2* _height;
}
string Rectangle::ToString()const{
	stringstream retVal;
	retVal << "Rectangle: {width: " << _width << ", height: " << _height <<  "}";
	return retVal.str();
}
void Rectangle::Double(){
	_width *= 2;
	_height*= 2;
}
