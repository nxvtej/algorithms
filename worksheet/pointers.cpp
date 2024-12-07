#include <iostream>
using namespace std;

int main()
{
    int *n = new int(10); // n points to dynamically allocated memory
    int &x = *n;          // x is a reference to the value at *n

    cout << "Address stored in n: " << n << endl; // Address of dynamically allocated memory
    cout << "Value at *n: " << *n << endl;        // Value is 10
    cout << "Value of x: " << x << endl;          // Same value, 10

    x++; // Increment the value referenced by x

    cout << "After incrementing x:" << endl;
    cout << "Address stored in n: " << n << endl; // Address is unchanged
    cout << "Value at *n: " << *n << endl;        // Value is updated to 11
    cout << "Value of x: " << x << endl;          // Value is 11

    delete n; // Free the allocated memory
    return 0;
}
