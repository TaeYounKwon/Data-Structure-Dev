#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

class Point{
	int x, y;
public:
	Point(int x, int y);
	void Read(istream& input);
	void Write(ostream& output)const;
	double Distance(const Point& point)const;
};

Point::Point(int x, int y): x(x), y(y){}

void Point::Read(istream& input){
	input >> x >> y;
}
void Point::Write(ostream& output)const{
	output << x << " " << y;
}
double Point::Distance(const Point& point)const{
	return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
}

int main(){
	Point a(1, 2), b(2, 3);
	string filename;
	cout << "File: ";
	cin >> filename;
/*	ofstream outputfile(filename);
	a.Write(outputfile);
	outputfile << endl;
	b.Write(outputfile);
	outputfile << endl;
	outputfile.close();
*/

	ifstream inputfile(filename);
	a.Read(inputfile);
	b.Read(inputfile);
	inputfile.close();
	a.Write(cout);
	cout << endl;
	b.Write(cout);
	cout << endl;

	return 0;
}
