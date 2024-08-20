#include <iostream>

class Base
{
public:
    void print()
    { // Non-virtual function
        std::cout << "Base class print function" << std::endl;
    }
};

class Derived : public Base
{
public:
    void print()
    { // Non-virtual function
        std::cout << "Derived class print function" << std::endl;
    }
};

class CC : public Derived
{
public:
    void print()
    { // Non-virtual function
        std::cout << "Derived 2 class print function" << std::endl;
    }
};

int main()
{
    Derived *a = new CC();
    a->print();
    return 0;
}
