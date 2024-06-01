#include <iostream>
using namespace std;
class ClassB;

class ClassA {
    public:

        ClassA() : numA(99) {}

    private:
        int numA;

        friend int largest(ClassA, ClassB);
};
class ClassB {
    public:
        ClassB() : numB(1) {}

    private:
        int numB;

        friend int largest(ClassA, ClassB);
};

int largest(ClassA objectA, ClassB objectB) {
    return (objectA.numA >objectB.numB)?objectA.numA : objectB.numB;
}

int main() {
    ClassA objectA;
    ClassB objectB;
    cout << "largest : " << largest(objectA, objectB);
    return 0;
}