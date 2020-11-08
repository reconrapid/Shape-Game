#include "Circle.h"
#include <math.h>    
#include <iostream>

using namespace std;

Circle::Circle() {
	diameter = 0;
	xCord = 0;
	yCord = 0;
}
Circle::Circle(float diameterOfCircle, float xCord, float yCord) {
	diameter = diameterOfCircle;
	this->xCord = xCord;
	this->yCord = yCord;
	radius = diameter / 2;
}
Circle::~Circle(void) {

}
void Circle::moveShape(float x, float y) {
	xCord = xCord + x;
	yCord = yCord + y;
}
void Circle::printShape() {
	cout << "Diameter of: " << diameter << " X value of: " << xCord << " Y value of: " << yCord << endl;
}
bool Circle::doesShapeOverlap(const Circle &v1) {
	if (sqrt((this->xCord - v1.xCord) * (this->xCord - v1.xCord) + (this->yCord - v1.yCord) * (this->yCord - v1.yCord)) < (v1.radius + this->radius)) {
		cout << "Circle & circle overlapping" << endl;
		return true;
	}
	cout << "Circle & circle doesnt overlap" << endl;
	return false;

}
bool Circle::doesShapeOverlap(const Square &v1) {
	Circle temp(v1.width, v1.xCord, v1.yCord);
	if (doesShapeOverlap(temp) == true) {
		return true;
	}
	else {
		return false;
	}
}
