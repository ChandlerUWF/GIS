#include "gis.hpp"
#include <iostream>

int main () {
    GIS taxMap;
    std::string fileName;
    int x, y;

    std::cout << "Please enter the file with the polygon data: ";
    std::cin >> fileName;
    while(!taxMap.ReadFile(fileName)) {
        std::cout << "Invalid file name!" << std::endl;
        std::cout << "Please enter the file with the polygon data: ";
        std::cin >> fileName;
    }

    std::cout << std::endl;
    std::cout << "Coordinates of query point (non-integer quits)" << std::endl;
    std::cout << "    x: ";
    while(std::cin >> x) {
        std::cout << "    y: ";
        std::cin >> y;
        Point point(x, y);
        std::cout << "Query point is inside: " << taxMap.GetParcel(point) << std::endl;
        std::cout << std::endl;
        std::cout << "Coordinates of query point (non-integer quits)" << std::endl;
        std::cout << "    x: ";
    }

    std::cout << std::endl;
    std::cout << "Thank you for using the program!" << std::endl;
}