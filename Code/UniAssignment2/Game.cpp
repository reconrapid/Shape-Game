#include "Circle.h"
#include "Square.h"
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

float sizeOfBoard = 0;
int numOfSquares = 0;
int numOfCircles = 0;
int maxShapeSize = 0;
int moveAmount = 0;

int wait;

int main() {

	// generate float random number, multiply by the range & then subtract to shift the center (to get minus numbers)
	//((float)rand()) / RAND_MAX * sizeOfBoard/2 - sizeOfBoard/2

	//How large do you want the board to be
	sizeOfBoard = 100;
	//How many squares do you want on the board
	numOfSquares = 5;
	//How many circles do you want on the board
	numOfCircles = 5;

	//Whats the limit on the width/diameter of each shape
	maxShapeSize = 40;

	//Vector array of all our shapes 
	vector<Square> squareArray;
	vector<Circle> circleArray;

	// Creating our cicles & squares
	for (int i = 0; i < numOfSquares; ++i) {
		squareArray.push_back(Square(((float)rand()) / RAND_MAX * maxShapeSize, ((float)rand()) / RAND_MAX * sizeOfBoard - sizeOfBoard / 2, ((float)rand()) / RAND_MAX * sizeOfBoard - sizeOfBoard / 2));
	}
	for (int i = 0; i < numOfCircles; ++i) {
		circleArray.push_back(Circle(((float)rand()) / RAND_MAX * maxShapeSize, ((float)rand()) / RAND_MAX * sizeOfBoard - sizeOfBoard / 2, ((float)rand()) / RAND_MAX * sizeOfBoard - sizeOfBoard / 2));
	}

	// Playing the game 
	while (circleArray.size()!=0 && squareArray.size()!=0) {
		cout << "Square Array Size " << squareArray.size() << '\n';
		cout << "Circle Array Size " << circleArray.size() << '\n';
		//Random modifer for how much the shapes will move, in this case they will move a random amount between -10 & 10 on both x & y 
		moveAmount = 20;

		//Moving everything
		cout << "MOVING SHAPES" << '\n';
		for (int i = 0; i < numOfSquares; ++i) {
			squareArray[i].moveShape(((float)rand()) / RAND_MAX * moveAmount - moveAmount / 2, ((float)rand()) / RAND_MAX * moveAmount - moveAmount / 2);
			//Checking if square out of bounds
			if ((squareArray[i].getX() > sizeOfBoard / 2) || (squareArray[i].getY() > sizeOfBoard / 2)) {
				squareArray[i].printShape();
				squareArray.erase(squareArray.begin() + i);
				numOfSquares = numOfSquares - 1;
			}
		}

		for (int i = 0; i < numOfCircles; ++i) {
			circleArray[i].moveShape(((float)rand()) / RAND_MAX * moveAmount - moveAmount / 2, ((float)rand()) / RAND_MAX * moveAmount - moveAmount / 2);
			//Checking if circle out of bounds
			if ((circleArray[i].getX() > sizeOfBoard / 2) || (circleArray[i].getY() > sizeOfBoard / 2)) {
				circleArray[i].printShape();
				circleArray.erase(circleArray.begin() + i);
				numOfCircles = numOfCircles - 1;
			}
		}


		//Checking for overlapping shapes
		//Checking if there are any circles & squares that overlap with each other
		for (int i = 0; i < numOfSquares; ++i) {
			for (int b = 0; b < numOfCircles; ++b) {
				if (squareArray[i].doesShapeOverlap(circleArray[b]) == true) {
					squareArray[i].printShape();
					circleArray[b].printShape();

					squareArray.erase(squareArray.begin() + i);
					circleArray.erase(circleArray.begin() + b);
					numOfCircles = numOfCircles - 1;
					numOfSquares = numOfSquares - 1;

				}
			}
		}
		// Checking if there any squares that overlap with each other 
		for (int i = 0; i < numOfSquares; ++i) {
			for (int b = i + 1; b < numOfSquares - 1; ++b) {
				if (squareArray[i].doesShapeOverlap(squareArray[b]) == true) {
					squareArray[i].printShape();
					squareArray[b].printShape();

					squareArray.erase(squareArray.begin() + i);
					squareArray.erase(squareArray.begin() + b);
					numOfSquares = numOfSquares - 2;
				}
			}
		}

		// Checking if there are any circles & circles that overlap with each other
		for (int i = 0; i < numOfCircles; ++i) {
			for (int b = i + 1; b < numOfCircles - 1; ++b) {
				if (circleArray[i].doesShapeOverlap(circleArray[b]) == true) {
					circleArray[i].printShape();
					circleArray[b].printShape();

					circleArray.erase(circleArray.begin() + i);
					circleArray.erase(circleArray.begin() + b);
					numOfCircles = numOfCircles - 2;
				}
			}
		}
	}

	cout << "End of game " << '\n';

	cin >> wait;
}