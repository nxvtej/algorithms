/*#include<bits/stdc++.h>
// #include<string.h>
using namespace std;
object of the question is to display personal and salary detail 
of three employee using single inheritance

class employee  
{
    public :
    string name , employee_no , designation ;

    public :
    employee ()
    {

        cout<<"enter the name of the employee "<<endl;
        // getline(cin,name);
        cin>>name;
        cout<<"enter the employee_no "<<endl;
        cin>>employee_no;
        cout<<"enter the designation"<<endl;
        cin>>designation;

    }
    void display();
};

void employee :: display()
{

    cout<<"employee name "<<name<<endl;
    cout<<"employee number "<<employee_no<<endl;
    cout<<"designation "<<designation<<endl;

}

class employee_salary : public employee
{
    private :
    float salary ;

instead of creating the direct object of base class in main
i can call the constructor of base class inside the constructor 
of derived class ; 


    public :
    employee_salary () : employee() 
    {
        cout<<"enter the employee salary : ";
        cin>>salary;
    }

    
    void display()
    {
        cout<<"salary of employee is : "<<salary<<endl;
    }

};


/*
i need to enter the data for 3 employee 
making 3 classes is stupid create 3 objects via array ;


int main(void)
{
    int number;

    cout<<"Enter the numbers of employee : ";
    cin>>number;

    /*employee_salary object[number] ; 

    for(int i=0; i<number; i++)
    {
        em

    }
    i think it's wrong as i have declared everything inside 
    the default constructor which means while 
    creating array every default constructor is called 
    so now 
    create object via for loop one by one .
    

    for(int i = 1 ; i <= number; i++)
    {
        employee_salary object[i];
        object[i].display();
    }
    // for(int i = 1 ; i <= number; i++)
    // {
    //     object[i].display();
    // }

    return 0 ;
}

*/

#include<iostream>
using namespace std;

class employee
{
    public :
    string name ;
    int age ;
    void getdata()
    {
        cout<<"enter your name \n";
        cin>>name ;
        cout<<"enter the age ";
        cin>>age;
    }
};

class salary : public employee
{
    public :
    int salary;

    void show()
    {
        cout<<"name : "<<name<<endl;
        cout<<"age : "<<age<<endl;
    }

};

int main()
{
    salary first ,second ,third ;
    // salary second ;
    // salary third ;
    first.getdata();
    first.show();
    second.getdata();
    second.show();
    third.getdata();
    third.show();


}
