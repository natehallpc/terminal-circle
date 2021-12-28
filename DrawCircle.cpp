#include "DrawCircle.h"
#include <iostream>
#include <cmath>

int main(int argc, char *argv[]){
    // Check if the radius is valid
    if (std::stoi(argv[0]) < 2){
        std::cout << "The minimum radius is 2.\nFor more help, type \"./DrawCircle help\"";
        return EXIT_FAILURE;
    }

    Circle newCircle(std::stoi(argv[0]));

    // Set the character to be printed as the edges of the circle.
    // If the edge argument is invalid or unspecified, use '.' as the edge character. 
    char edgeChar = '.';
    if (argc == 2){
        std::string charArg = argv[1];
        if (charArg.length() > 1){
            std::cout << "Edge parameter (second argument) should be a single character.\nFor more help, type \"./DrawCircle help\"" << std::endl;
        } else {
            edgeChar = charArg[0];
        }
        
    }
    // Print the circle.
    std::cout << newCircle.toString(edgeChar) << std::endl;
    return EXIT_SUCCESS;
}

Circle::Circle(int radius){
    diameter = (radius * 2) + 1;
}


std::string Circle::toString(char edgeChar){
    std::string circleString = "";
    for (int i = 0; i < diameter; i++)
        circleString += getLine(i, edgeChar);
    return circleString;
}

std::string Circle::getLine(int index, char edgeChar){
    double theta = asin(index / diameter);
    int x = (cos(theta) * diameter);
    int precedingSpaces = (diameter / 2) - x;
    std::string line = "";
    for (int i = 0; i < precedingSpaces; i++)
        line += ' ';
    line += edgeChar;
    return line;
}