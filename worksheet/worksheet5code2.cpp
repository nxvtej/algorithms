// /* Define a class Student with data members 
// as roll no and name. 
// Derive a class Fees from Student 
// that has a data member fees and function
// to submit fees and generate receipt.
// Derive another class Result from Student that 
// displays the marks and grade obtained by the student. 
// Make use of constructor to initialize the value of 
// the data members in the base class and derived class.  
// */

// #include<bits/stdc++.h>
// #include<string> 
// using namespace std;

// class student
// {
//     protected :
//     string name ;
//     int  roll_no ;
    
//     public :
//     /*
//     if it wasn't compulsory this  can be done in another function
//     */
//     student()
//     {}

//     student (int name) 
//     {
//         this->roll_no = roll_no;
//     }

//     student (string n)
//     {
//         this->name = name;
//     }

//     void print ()
//     {
//         cout<<"Name : "<<name<<endl<<"roll_no : "<<roll_no<<endl;
//     }

// };

// class  fees : public student
// {
//     protected :
//     float fee ;
//     string n ;
//     int roll ;

//     public :
//     fees () //: student () 
//     {
//         cout<<"enter the fees amount to be paid : ";
//         cin>>fee;

//         cout<<"enter the name\n";
//         cin>>n;

//         cout<<"enter the roll number \n";
//         cin>>roll;

//         student(n);
//         student(roll);
//     }
//     void submit_fees() ;
//     void generate_fees() ;

// };

// void fees :: submit_fees()
// {
//     cout<<"enter the submitted amount : ";
//     cin>>fee;
// }

// void fees :: generate_fees()
// {
//     // (fee==1000) ? ( cout<<"you have submitted a fee \n" ; ) : (cout<<"pending fees is : "<<1000-fee <<endl;) 
//     if(fee==1000)
//     cout<<"you have submitted a fee\n";
//     else if(fee>1000)
//     cout<<"extra fee submitted : "<<fee-1000<<endl;
//     else
//     cout<<"pending fee is : "<<1000-fee <<endl;
// }

// class result : public student
// {
//     protected :
//     int marks[3] ,average_marks, total_marks = 0;  // assuming only three subjects ;
//     char grade ;
    
//     /*
//     now here if i think calling it via constructor will help
//     but it shows error ;;;;;;;;;;
//     */
//     public :
//     result ()  
//     {
//         cout<<"enter the marks of three subjects : \n";
//         for(int i=0; i<3;i++)
//         {
//             cin>> marks[i];
//             total_marks+=marks[i];
//         }
//     }
    
//     void show_result();
// };

// void result :: show_result ()

// {
//     average_marks = total_marks/3;

//     switch (int(average_marks/10))
//     {
//         case 10 :
//         {
//             cout<<"A"<<endl;
//             break;
//         }

//         case 9 :
//         {
//             cout<<"B"<<endl;
//             break;
//         }

//         case 8 :
//         {
//             cout<<"C"<<endl;
//             break;
//         }

//         case 7 :
//         {
//             cout<<"D"<<endl;
//             break;
//         }

//         default :
//         {
//             cout<<"F"<<endl;
//             break ;
//         }

//     }
// }
// /*
// now, here in this code problem arises as the object of the 
// base class is to be created 
// which is not preferable ; 
// */
// /*
// and to over come this 
// insidse the derived class constructor calling 
// we can define the constructor for the base class ; 
// */

// int main(void)
// {
// /*
// here both the time the constructor is called 
// base class constructor ;
// how to over comeee?????????????????
// im going madddddddddddddddddd,,,,,,,,,,
// */
// /*
// so i need to create a parametrised constructor 
// in base to get data their .
// */
// /*
// so
// after so many tries 
// only one way
// pass one value from one derived class and another from another class
        
// */
//     fees fees_object;
//     result result_object;


// }
/*
#include<iostream>
using namespace std;
class Student
{
public:
string name;
int roll_no;
Student()
{
cout<<"enter the name : ";
cin>>name;
cout<<"enter the roll number : ";
cin>>roll_no;
}
};
class Fee : public Student
{
int fees;
public:
Fee()
{
cout<<"enter the amount ot be submitted : ";
cin>>fees;
}
void generate()
{
cout<<"Name : "<< name <<endl;
cout<<"Roll no. : "<< roll_no <<endl;
cout<<"Fees submitted : "<< fees << endl;
}
};
class Result : public Student
{
int a,b,c,percentage;
char grade;
public:
Result()
{
cout<<"enter the marks in first subject : ";
cin>>a;
cout<<"enter the marks in secound subject : ";
cin>>b;
cout<<"enter the marks in third subject : ";
cin>>c;
percentage = (a+b+c)/3;
if(percentage>80)
grade = 'A';
else if(percentage>60)
grade = 'B';
else
grade ='C';
}
void show()
{
cout<<"Name : "<< name <<endl;
cout<<"Roll no. : "<< roll_no <<endl;
cout<<"Percentage : "<< percentage<< endl;
cout<<"Grade : "<<grade<<endl;
}
};
int main()
{
Fee obj;
obj.generate();
Result obj1;
obj1.show();
}*/
#include<bits/stdc++.h>
using namespace std;
class Student{
string name;
int roll_no;
public:
// using the parametrized constructor as the constructor parameter
// will be called every time the derived class constructor
// run . so taking theparametrized 
Student(string name){
this->name=name;
}
Student(int roll_no){
this->roll_no=roll_no;
}
// not taking same name as their is variable of same name 
void nme(){
cout<<"Name of the student is "<<name<<endl;
}
void r_no(){
cout<<"Roll_no is "<<roll_no<<endl;
}
// to display the name and the roll number 
};

class Fees:public Student
{
    private : 
int fees;
public:

Fees (string nm ,int fees) : Student(nm)
{
this->fees=fees;
}
void receipt(){
if(fees==9000)
cout<<"fee ahs been submitted "<<endl;
else
cout<<"Remaining fees is "<<(9000-fees)<<endl;
}
};

class Result:public Student
{
    int marks;
char grade;
public:
Result(int rolln,int marks,char grade):Student(rolln){
this->marks=marks;
this->grade=grade;
}
// directly passing the values 
// inside the cosntructor 

void mks_and_grd(){
cout<<"Marks obtained is "<<marks<<" and grade is "<<grade<<endl;
}
};
int main(){
Fees object1("navdeep",5000);
object1.nme();
object1.receipt();
Result object11(1,9,'A');
object11.r_no();
object11.mks_and_grd();
return 0;
}