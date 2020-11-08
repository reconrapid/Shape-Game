#pragma once
#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
	//Friend classes (Allows access to private members of Shape)
	friend class Square;
	friend class Circle;

public:

	float getWidth();

	float getHeight();

	float getX();

	float getY();

	virtual void moveShape(float x, float y) = 0;

	virtual bool doesShapeOverlap(const Square &v1) = 0;

	virtual bool doesShapeOverlap(const Circle &v1) = 0;

	virtual void printShape() = 0;


private:
	// Used to track position on 2D space
	float xCord;      // x coordinate 
	float yCord;     // y coordinate 

	float width;
	float height;


};
#endif