#include <iostream>
using namespace std;
class Employee
{
    string name, designation;

public:
    Employee(string name, string designation)
    {
        this->name = name;
        this->designation = designation;
    }
    void display()
    {
        cout << "Name of the Employee is " << name << "\n designation is " << designation << endl;
    }
};

class Qualification
{
    string UG, PG;

public:
    Qualification(string UG, string PG)
    {
        this->UG = UG;
        this->PG = PG;
    }

    void qual()
    {
        cout << "UG in " << UG << " \n PG in " << PG << endl;
    }
};
class Salary : public Employee, public Qualification
{
    int salary;

public:
    Salary(string n1, string dsgn, string u, string p, int salary) : Employee(n1, dsgn), Qualification(u, p)
    {
        this->salary = salary;
    }
    void slrry()
    {
        cout << "Salary of the Employee is " << salary << endl;
    }
};
int main()
{
    Salary s1("Navdeep", "CEO", "CSE", "MBA", 199000);
    s1.display();
    s1.qual();
    s1.slrry();
    return 0;
}