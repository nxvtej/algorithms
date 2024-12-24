#include <bits/stdc++.h>
using namespace std;

class demo
{
public:
    string name = "";

    demo(string name) : name(name)
    {
        cout << "param constructor: " << name << endl;
    }

    demo(const demo &demo)
    {
        name = demo.name;
        cout << "copy constructir called :" << name << endl;
    }

    ~demo()
    {
        cout << "destructor demo " << name << endl;
    }
};

void testing_push_back()
{
    vector<demo> vec;

    vec.push_back(demo("1st"));
    vec.push_back(demo("2nd"));
    vec.push_back(demo("3rd"));
    vec.push_back(demo("4th"));

    // error here
    // vec.push_back("nav");
    /*
    for (auto it : vec)
    {
        cout << it.name << endl;
    }

    */
}

void testing_emplace_back()
{
    cout << "Testing emplace back\n";
    vector<demo> vec;

    /*
        vec.emplace_back(demo("1st"));
        vec.emplace_back(demo("2nd"));
        vec.emplace_back(demo("3rd"));
    */
    // correrct usage

    vec.emplace_back("hey");
    vec.emplace_back("there");
    vec.emplace_back("nav");
}

int main()
{
    // testing_push_back();
    testing_emplace_back();
}