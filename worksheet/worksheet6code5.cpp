// A program with virtual destructor
#include <iostream>

using namespace std;

class base {
public:
	base()	
	{ cout << "Constructor of base called" << endl;}
    ~base()
	{ cout << "Destructor of base called" << endl; }	
};

class derived : public base {
public:
	derived()	
	{ cout << "Constructor of derived called" << endl; }
    ~derived()
	{ cout << "Destructor of derived called" << endl; }
};

int main()
{
derived *d = new derived();
base *b = d;
delete b;
// getchar();
return 0;
}