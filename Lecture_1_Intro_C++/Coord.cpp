#include "coord.h"

int main() {
	Coord c = Coord();

	c.Initialize(10.0,4.2);

	c.Print();

	c.Reflect();

	c.Print();
}