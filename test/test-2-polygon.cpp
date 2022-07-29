#include "catch/catch.hpp"
#include "polygon.hpp"
#include <iostream>

TEST_CASE ("Polygon tests")
{
	// polygon with 0 vertices
	Polygon empty;

	// prepare list of points to create square
	Point points[] = {Point(0,0), Point(0,2), Point(2,2), Point(2,0)};
	Polygon square("My square", points, 4);

	SECTION ("Default Constructor")
	{
		CHECK(0 == empty.GetVertexCount());
		CHECK("" == empty.GetName());
	}

	SECTION ("Parameterized Constructor")
	{
		CHECK(4 == square.GetVertexCount());
		CHECK("My square" == square.GetName());
		// index 1 is the second Point from the input above
		CHECK(Point(0,2) == *(square.GetVertex(1)));
	}

	SECTION ("Ensure object copy/assignment are not shallow")
	{
		Polygon otherSquare = square;
		CHECK(Point(0,2) == *(square.GetVertex(1)));

		// update second square to somewhere in quadrant 3
		Point points[] = {Point(-1,-1), Point(-1,-3), Point(-3,-3), Point(-3,-1)};
		otherSquare = Polygon("Other square", points, 4);
		CHECK(Point(-1,-1) == *(otherSquare.GetVertex(0)));

		// ensure that updating one didn't impact the other
		CHECK(Point(0,2) == *(square.GetVertex(1)));

		// Verify reassigning to self isn't broken
		otherSquare = otherSquare;
		CHECK(Point(-1,-1) == *(otherSquare.GetVertex(0)));
	}
}
