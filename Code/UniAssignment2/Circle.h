#pragma once
#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"
#include "Square.h"


class Circle : public Shape {

protected:
	float radius;
	float centre;
	float diameter;

public:

	Circle();

	Circle(float diameterOfCircle, float xCord, float yCord);

	void moveShape(float x, float y);

	void printShape();

	bool doesShapeOverlap(const Circle &v1);

	bool doesShapeOverlap(const Square &v1);

	~Circle(void);



};
#endif