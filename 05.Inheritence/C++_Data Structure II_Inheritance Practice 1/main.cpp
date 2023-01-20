#include "rectangle.h"
#include "square.h"
#include "point.h"

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[]){
	Rectangle r(Point(0,0), 2, 3);
	cout << r.ToString() << endl;
	cout << r.Perimeter() << endl;
	cout << r.Area() << endl;

	Square s(Point(4,2), 10);
	cout << s.ToString() << endl;
	cout << s.Perimeter() << endl;
	cout << s.Area() << endl;


	return 0;
}
