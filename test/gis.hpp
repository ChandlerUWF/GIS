#ifndef GIS_HPP
#define GIS_HPP

#include "polygon.hpp"
#include <fstream>
#include <sstream>
#include <vector>

class GIS{
    private:
        std::vector<Polygon> maps;
    public:
        static std::string NOT_FOUND;
        GIS();
        bool ReadFile(std::string fileName);
        std::string GetParcel(Point p1);
};

#endif