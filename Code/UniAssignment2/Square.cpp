#include "Square.h"
#include <iostream>

using namespace std;

Square::Square() {
	height = 0;
	width = 0;
	xCord = 0;
	yCord = 0;
}
Square::Square(float x, float xCord, float yCord) {
	height = x;
	width = x;
	this->xCord = xCord;
	this->yCord = yCord;
}
Square::~Square(void) {

}
void Square::moveShape(float x, float y) {
	xCord = xCord + x;
	yCord = yCord + y;
}
void Square::printShape() {
	cout << "Height & Width of: " << height << " X value of: " << xCord << " Y value of: " << yCord << endl;
}
bool Square::doesShapeOverlap(const Square &v1) {

	if ((this->xCord <= (v1.xCord + v1.width) && (this->xCord + this->width) >= v1.xCord)
		&& (this->yCord <= (v1.yCord + v1.width) && (this->yCord + this->width) >= v1.yCord)) {
		cout << "Square & Square overlapping" << endl;
		return true;
	}
	else {
		cout << "Square & Square doesnt overlap" << endl;
		return false;
	}
}
bool Square::doesShapeOverlap(const Circle &v1) {
	Circle temp(this->width, this->xCord, this->yCord);
	if (temp.doesShapeOverlap(v1) == true) {
		return true;
	}
	else {
		return false;
	}
}