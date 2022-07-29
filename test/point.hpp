#ifndef POINT_HPP
#define POINT_HPP

class Point{
    private:
        int x;
        int y;
    public:
        Point();
        Point(int x, int y);
        Point(const Point& p1);
        Point& operator=(const Point& rhs);
        friend bool operator==(const Point& lhs, const Point& rhs);
        int GetX();
        int GetY();
};

#endif