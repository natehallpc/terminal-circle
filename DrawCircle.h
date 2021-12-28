#include <string>

class Circle
{
public:
    Circle(int radius);
    std::string toString(char edgeChar);
private:
    int diameter;
    std::string getLine(int index, char edgeChar);
};
