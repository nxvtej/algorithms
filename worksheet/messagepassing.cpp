#include <iostream>
using namespace std;

class Animal
{
public:
    // Virtual method (can be overridden by derived classes)
    virtual void makeSound()
    {
        cout << "Some generic animal sound!" << endl;
    }
};

class Dog : public Animal
{
public:
    void makeSound() override
    {
        cout << "Woof! Woof!" << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        cout << "Meow! Meow!" << endl;
    }
};

void sendSoundMessage(Animal &animal)
{
    // Message passing: Calls the appropriate makeSound() method based on the object type
    animal.makeSound();
}

int main()
{
    Dog myDog;
    Cat myCat;

    sendSoundMessage(myDog); // Message passing to Dog object
    sendSoundMessage(myCat); // Message passing to Cat object

    return 0;
}
