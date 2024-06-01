#include<iostream>
using namespace std;

// making code using function only;

void grandchildren()
{
    double number = 6.325;
    cout<<"Grand children comes at last!"<<endl;
    throw number;
    cout<<"they were borned \n";
}

void children()
{
    cout<<"THEN comes children \n";
    grandchildren();
    cout<<"they were born second \n";
}

void parents()
{
    cout<<"here comes pita shri \n";
    children();
    cout<<"and here goes the pita shree\n";
}

void dada_ji ()
{
    cout<<"namaskaram dada ji\n";
    try
    {
    parents();
    }
    catch(const double err)
    {
        cout<<"error\n";
        std::cerr << err << '\n';
    }
    cout<<"at last dada ji went away\n";
}

int main(void)
{
    cout<<"lo sir , code starts here in main\n";
    dada_ji();
}
/*
// CPP Program to demonstrate Stack Unwinding
#include <iostream>
#include<stdexcept> 
using namespace std;

// A sample function f1() that throws an int exception
void f1()
{
	cout << "\n f1() Start ";
	throw 100;
	cout << "\n f1() End ";
}

// Another sample function f2() that calls f1()
void f2()
{
	cout << "\n f2() Start ";
	f1();
	cout << "\n f2() End ";
}

// Another sample function f3() that calls f2() and handles
// exception thrown by f1()
void f3()
{
	cout << "\n f3() Start ";
	try {
		f2();
	}
	catch (int i) {
		cout << "\n Caught Exception: " << i;
	}
	cout << "\n f3() End";
}

// Driver Code
int main()
{
	f3();

	getchar();
	return 0;
}

*/