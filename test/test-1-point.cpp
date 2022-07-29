#include "catch/catch.hpp"
#include "point.hpp"

TEST_CASE ("Point Default Constructor")
{
	Point p; // default point - at origin (0,0)
	CHECK(0 == p.GetX());
	CHECK(0 == p.GetY());
}

TEST_CASE ("Point Parameterized Constructor")
{
	Point p(3,2);
	CHECK(3 == p.GetX());
	CHECK(2 == p.GetY());
}

TEST_CASE ("Test equality")
{
	Point p1(4, 12);
	Point p2(12, 4);
	Point p3(4, 12);

	CHECK(p1 == p3);
	CHECK(!(p1 == p2));
}
