#pragma once
#ifndef SQUARE_H_
#define SQUARE_H_

#include "Shape.h"
#include "Circle.h"


class Square : public Shape {

protected:

public:

	Square();

	Square(float x, float xCord, float yCord);

	void moveShape(float x, float y);

	void printShape();

	bool doesShapeOverlap(const Square &v1);

	bool doesShapeOverlap(const Circle &v1);

	~Square(void);



};
#endif