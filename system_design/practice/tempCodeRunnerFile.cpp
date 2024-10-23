#include <iostream>
using namespace std;

class singleton
{
public:
    static singleton *instance;
    singleton()
    {
        cout << "Constructor called" << endl;
    }

    static singleton *getsingletonInstance()
    {

        if (instance == nullptr)
        {
            instance = new singleton();
        }

        return instance;
    }
};

singleton *singleton::instance = nullptr;
int main()
{
    // singleton *firstInstance = singleton::getsingletonInstance();
    // singleton *secondInstance = singleton::getsingletonInstance();

    singleton firstInstance;
    singleton secondInstance;

    if (&firstInstance == &secondInstance)
        cout << "yeah it works\n";
    else
        cout << "nope wrong way!!";

    return 0;
}