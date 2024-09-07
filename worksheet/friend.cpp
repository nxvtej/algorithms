// if no objrct passed then friendd funcvtion wont be able to access anyuthign
#include <iostream>
using namespace std;

class Box; // Forward declaration of Box class

class Cylinder
{
private:
    double radius;
    double height;

public:
    Cylinder(double r, double h) : radius(r), height(h) {}

    // Declare a friend function that will work with both Box and Cylinder
    friend void compareVolume(const Box &box, const Cylinder &cylinder);
};

class Box
{
private:
    double length;
    double width;
    double height;

public:
    Box(double l, double w, double h) : length(l), width(w), height(h) {}

    // Declare the same friend function in the Box class
    friend void compareVolume(const Box &box, const Cylinder &cylinder);
};

// Friend function that works with both Box and Cylinder objects
void compareVolume(const Box &box, const Cylinder &cylinder)
{
    double boxVolume = box.length * box.width * box.height;
    double cylinderVolume = 3.1415 * cylinder.radius * cylinder.radius * cylinder.height;

    if (boxVolume > cylinderVolume)
    {
        cout << "The box has a larger volume." << endl;
    }
    else
    {
        cout << "The cylinder has a larger volume." << endl;
    }
}

int main()
{
    Box myBox(5.0, 4.0, 3.0);
    Cylinder myCylinder(2.0, 10.0);

    // Call the friend function by passing objects of both classes
    compareVolume(myBox, myCylinder);

    return 0;
}
