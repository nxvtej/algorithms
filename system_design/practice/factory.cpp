#include <iostream>
using namespace std;

class Vechicle
{
public:
    virtual void create() = 0;
};

class Bike : public Vechicle
{
public:
    void create()
    {
        cout << "Creating a Bike" << endl;
    }
};

class Bus : public Vechicle
{
public:
    void create()
    {
        cout << "Creating a Bus" << endl;
    }
};

class Car : public Vechicle
{
public:
    void create()
    {
        cout << "Creating a Car" << endl;
    }
};

class factory
{
public:
    Vechicle *createVehicle(string s)
    {
        if (s == "bike")
        {
            return new Bike();
        }
        else if (s == "bus")
        {
            return new Bus();
        }
        else if (s == "Car")
        {
            return new Car();
        }

        return nullptr;
    }
};

int main()
{
    factory *f = new factory();
    Vechicle *v = f->createVehicle("bike");
    v->create();
    return 0;
}