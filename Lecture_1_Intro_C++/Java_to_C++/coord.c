#include "coord.h"
#include <iostream>

void Coord::Initialize(double xInit, double yInit) {
	xCoord = xInit;
	yCoord = yInit;
}

void Coord::Reflect() {
	double temp = xCoord;
	xCoord = yCoord;
	yCoord = temp;
}

void Coord::Print() {
	std::cout << xCoord << ", " << yCoord << std::endl;
}