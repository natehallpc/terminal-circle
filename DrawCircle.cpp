#include "DrawCircle.h"
#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
    double horizVertRatio = 2.0;

    // Check if the radius is valid
    if (std::stoi(argv[1]) < 2)
    {
        std::cout << "The minimum radius is 2.\nFor more help, type \"./DrawCircle help\"" << std::endl;
        return EXIT_FAILURE;
    } else if ((std::stoi(argv[1]) * horizVertRatio) > 80) {
        std::cout << "The maximum radius is " << ((80 / horizVertRatio) - 1) << ".\nFor more help, type \"./DrawCircle help\"" << std::endl;
        return EXIT_FAILURE;
    }

    Circle newCircle(std::stoi(argv[1]));

    // Set the character to be printed as the edges of the circle.
    // If the edge argument is invalid or unspecified, use '.' as the edge character.
    char edgeChar = '.';
    if (argc == 3)
    {
        std::string charArg = argv[2];
        if (charArg.length() > 1)
        {
            std::cout << "Edge parameter (second argument) should be a single character.\nFor more help, type \"./DrawCircle help\"" << std::endl;
            return EXIT_FAILURE;
        }
        edgeChar = charArg[0];
    }

    // Print the circle.
    std::cout << newCircle.toString(edgeChar, horizVertRatio) << std::endl;
    return EXIT_SUCCESS;
}

Circle::Circle(int radius)
{
    
    this->radius = radius;
    this->diameter = ((radius * 2) + 1);
}

std::string Circle::toString(char edgeChar, double horizVertRatio)
{
    std::string circleString = "";
    for (int i = 0; i < diameter; i++)
    {
        circleString += getLine(i, edgeChar, horizVertRatio);
        if (i < diameter - 1)
            circleString += '\n';
    }
    return circleString;
}

std::string Circle::getLine(double index, char edgeChar, double horizVertRatio)
{
    double theta = asin((radius - index) / radius);
    std::cout << "Theta: " << theta << std::endl;
    int x = (cos(theta) * radius);
    std::cout << "x: " << x << std::endl;
    int precedingSpaces = radius - x;
    std::cout << "Printing this edge at index " << precedingSpaces << std::endl;
    std::string line = "";
    for (int i = 0; i < precedingSpaces; i++)
        line += ' ';
    line += edgeChar;
    if (precedingSpaces != radius)
    {
        for (int i = 0; i < ((radius - precedingSpaces) * 2) - 1; i++)
            line += ' ';
        line += edgeChar;
    }
    return line;
}