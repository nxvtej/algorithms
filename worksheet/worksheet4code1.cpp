#include <iostream>
using namespace std;

class students
{
    private : 
    string name;

    public :
    students(string s) : name(s)
    {}
    students():name("Unknown")
    {}
    void show_name()
    {
        cout<<name<<endl;
    }
};

int main(void)
{
    students test_case_1("Navdeep");
    students test_case_2;


    test_case_1.show_name();
    test_case_2.show_name();

}