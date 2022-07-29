#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "point.hpp"
#include "matrix3d.hpp"
#include <string>

class Polygon {
    private:
        std::string name;
        int vertexCount;
        Point *points;
    public:
        Polygon();
        Polygon(std::string name, Point points[], int vertexCount);
        Polygon(const Polygon& poly);
        ~Polygon();
        Polygon& operator=(const Polygon& rhs);
        std::string GetName();
        int GetVertexCount();
        Point* GetVertex(int index);
        bool Contains(Point p);
};
#endif