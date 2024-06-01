#include <iostream>
using namespace std;
class B;

class A {
    
    public:
        
        A() : numA(99) {}
        
    private:
        int numA;
        
        
        friend int add(A, B);
};

class B {

    public:
        
        B() : numB(1) {}
    
    private:
        int numB;

        
        friend int add(A, B);
};

int add(A objectA, B objectB) {
    return (objectA.numA + objectB.numB);
}

int main() {
    A objectA;
    B objectB;
    cout << "Sum: " << add(objectA, objectB);
    return 0;
}