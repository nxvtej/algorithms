#include <iostream>
using namespace std;

class trick
{
public:
    // virtual int a;
    virtual void greet() {}
};

class greeting : public trick
{
private:
    void greet()
    {
        cout << "hi there from private";
    }
};

int main()
{
    trick *obj = new greeting();
    obj->greet(); // Output: hi there
    return 0;
}