#include "polygon.hpp"

Polygon::Polygon() {
    this->name = "";
    this->vertexCount = 0;
    this->points = new Point[vertexCount];
}

Polygon::Polygon(std::string name, Point points[], int vertexCount) {
    this->name = name;
    this->vertexCount = vertexCount;
    this->points = new Point[vertexCount];
    for(int i = 0; i < vertexCount; i++) {
        this->points[i] = points[i];
    }
}

Polygon::Polygon(const Polygon& poly) {
    name = poly.name;
    vertexCount = poly.vertexCount;
    points = new Point[vertexCount];
    for(int i = 0; i < vertexCount; i++) {
        points[i] = poly.points[i];
    }
}

Polygon::~Polygon() {
    delete [] points;
}

Polygon& Polygon::operator=(const Polygon& rhs) {
    if(&rhs != this) {
        delete[] points;
        name = rhs.name;
        vertexCount = rhs.vertexCount;
        points = new Point[vertexCount];
        for(int i = 0; i < vertexCount; i++) {
            points[i] = rhs.points[i];
        }
    }
    return *this;
}

std::string Polygon::GetName() {
    return name;
}

int Polygon::GetVertexCount() {
    return vertexCount;
}

Point* Polygon::GetVertex(int index) {
    Point* pointPtr = &(points[index]);
    return pointPtr;
}

bool Polygon::Contains(Point p) {
    if(vertexCount < 3) { // Returns false if vertexCount is less than 3, since a polygon cannot have less than 3 points
        return false;
    }
    // Iterating through the points array, and creating a new Matrix3D object each time in order to compare every two vertices
    for(int i = 0; i < vertexCount; i++) {
        if(i == (vertexCount - 1)) {
            Matrix3D matrix(1,points[i].GetX(),points[i].GetY(), 1, points[0].GetX(),points[0].GetY(), 1,p.GetX(),p.GetY());
            if(matrix.Determinant() > 0) {
                break;
            }
            else {
                return true;
            }
        }
        Matrix3D matrix(1,points[i].GetX(),points[i].GetY(), 1, points[i+1].GetX(),points[i+1].GetY(), 1,p.GetX(),p.GetY());
        if(matrix.Determinant() > 0) {
            break;
        }
        else {
            continue;
        }
    }
    return false;
}