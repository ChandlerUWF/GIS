#include "point.hpp"
using namespace std;

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point& p1) {
    x = p1.x;
    y = p1.y;
}

Point& Point::operator=(const Point& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    return *this;
}

bool operator==(const Point& lhs, const Point& rhs) {
    if((lhs.x == rhs.x) && (lhs.y == rhs.y)) {
        return true;
    }
    else {
        return false;
    }
}

int Point::GetX() {
    return x;
}

int Point::GetY() {
    return y;
}