// C++ Program to changing the
// address pointed by pointer
#include <iostream>
using namespace std;

// Driver code
int main()
{
    int a = 10, b = 20;
    int *pt;

    // Referencing to the pointer
    pt = &a;

    cout << "The address where a is stored is: " << pt
         << endl;

    // dereference the pointer
    cout << "The value stored at the address by "
            "dereferencing the pointer is: "
         << *pt << endl;

    // Referening the address to same pointer
    pt = &b;

    // dereference the pointer
    cout << "Pointer is now pointing at: " << pt << endl;
    cout << "New value the pointer is pointing to is: "
         << *pt << endl;

    return 0;
}
