/*
terminate() when called by default abort the program.
unexpected() when called calls terminate() .

unexpected() is called when a function with exception specification throws an exception
an exception of type that is not listed in the exception specification.
*/

#include <iostream>
using namespace std;

void myterminate() 
{
    cout<<"myterminate() handler is called :"<<endl;
    abort();
}
void myunexpected()
{
    cout<<"myunexpected() handler is called :"<<endl;
}

void foo()
{
    throw "throw";
}
int main()
{
    set_terminate(myterminate);
    set_unexpected(myunexpected);

    try
    {
        
        
        foo();
    }
    catch(const float)
    {
        std::cerr <<" caught it broken\n"; 
    }

    return 0;
}