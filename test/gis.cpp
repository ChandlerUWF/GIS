#include "gis.hpp"

GIS::GIS() {

}

std::string GIS::NOT_FOUND = "not present";

bool GIS::ReadFile(std::string fileName) {
    
    //Reads a file containing a polygon's name and vertices
    std::ifstream fileInput(fileName);
    if(!fileInput) {
        return false; //Returns false if the file does not exist
    }

    std::string name;
    std::string line;
    int x, y;
    
    //Iterates through the file line by line, and stores the current line in a string
    //Then goes through the line and stores the points of the polygon
    while(std::getline(fileInput, line)) {
        std::istringstream iss(line);
        if(iss >> name) {
            int vertexCount = 0;
            std::vector<Point> p;
            while(iss >> x >> y) {
                Point point(x, y);
                p.push_back(point);
                vertexCount++;
            }
            Point points[vertexCount];
            for(int i = 0; i < vertexCount; i++) {
                points[i] = p.at(i);
            }
            Polygon poly(name, points, vertexCount);
            maps.push_back(poly);
        }
    }
    return true;
}

std::string GIS::GetParcel(Point p1) {
    for(int i = 0; i < maps.size(); i++) {
        if(maps.at(i).Contains(p1)) {
            return maps.at(i).GetName();
        }
    }
    return NOT_FOUND;
}
