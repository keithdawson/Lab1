#include <string>
#include <iostream>
#include <math.h>
using namespace std;


class Triangle {
private:
	double x[3],y[3];
public:
	Triangle (){
		x[0]=0; y[0]=4;
		x[1]=5; y[1]=2;
		x[2]=4; y[2]=1;
	};
	Triangle(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y){
		x[0]=p1x; y[0]=p1y;
		x[1]=p2x; y[1]=p2y;
		x[2]=p3x; y[2]=p3y;
	}
                                            // specifies the three points
    string toString ( ){
	    return "(" + to_string(x[0]) + "," + to_string(y[0]) + "), (" + to_string(x[1]) + "," + to_string(y[1]) + "), (" + to_string(x[3]) + "," + to_string(y[3]) + ")";
                                            };                    // creates the string in the form “(x,y), (x,y), (x,y)”
	double get (int point, char c);         // return the coordinate for the index,
                                            // c should be ‘x’ or ‘y’
	void put (int point, char c, double v); // Store value v in the point specified as above
	double perimeter ( );                   // return the perimeter of the triangle
	double area ( ){
		// int i, j;
		double areaVal;
		// p1x = x[0], p1y = y[0], p2x = x[1], p2y = y[1], p3x = x[2], p3y = y[2];
		areaVal = ( x[0] * ( y[1] - y[2] ) + x[1] * ( y[2] - y[0] ) + x[2] * ( y[0] - y[1] ))/2.0;
		return areaVal;
	};                        // return the area of the triangle
};

ostream& operator<< (ostream& os, Triangle t){
	return os << t.toString();
};

double Triangle::perimeter() {
	double perimeter;
	double distance, tempx, tempy;

	tempx = (x[0] - y[0]);
	tempx = pow(tempx, 2.0f);
	tempy = (x[1] - y[1]);
	tempy = pow(tempy, 2.0f);
	distance = tempx + tempy;
	distance = sqrt(distance);
	perimeter += distance;

	tempx = (x[2] - y[2]);
	tempx = pow(tempx, 2.0f);
	tempy = (x[1] - y[1]);
	tempy = pow(tempy, 2.0f);
	distance = tempx + tempy;
	distance = sqrt(distance);
	perimeter += distance;

	tempx = (x[0] - y[0]);
	tempx = pow(tempx, 2.0f);
	tempy = (x[2] - y[2]);
	tempy = pow(tempy, 2.0f);
	distance = tempx + tempy;
	distance = sqrt(distance);
	perimeter += distance;
	return perimeter;
}

double Triangle::get(int point, char c){

	if (c == 'x') return x[point];
	else return y[point];
}

void Triangle::put(int point, char c, double v){
	(c == 'x') ? x[point] = v : y[point] = v;
}

int main() {
	Triangle t1;
	cout << t1 << endl;
	cout << t1.area() << endl;
	cout << t1.perimeter() << endl;
	cout << endl;
	Triangle t2(-1, 0, 1, 0, 0, 1);
	cout << t2 << endl;
	cout << t2.area() << endl;
	cout << t2.perimeter() << endl;
	cout << endl;
}