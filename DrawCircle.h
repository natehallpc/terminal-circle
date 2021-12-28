#include <string>

class Circle
{
public:
    Circle(int radius);
    std::string toString(char edgeChar, double horizVertRatio);
private:
    double radius;
    double diameter;
    std::string getLine(double index, char edgeChar, double horizVertRatio);
};
