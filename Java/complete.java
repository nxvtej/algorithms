/*class student
{
    String name;
    int age;
    
    student(String name, int age)
    {
        this.name = name;
        this.age = age;
    }
    public void printinfo()
    {
       System.out.println(this.name);
    }
}
public class complete
{
    public static void main(String[] args)
    {
        

        student s1 = new student("navdeep", 19); //memory heap stores memory according to the object  ; 
                                    //it's a funciton constructor ;
                                    // fucntion is to create something in this case object ;
                                    // it's a non parameterized constructor ;
                                    // class name and constructor name are same
                                    // they don't return anything and ahve no return type ;
                                    // constructor can be called only once ;
                                    // it creates constructor by default ;
                                    // all copy constructors are user defined


       
    
        s1.printinfo();
    }
}
*/

/* 
*****************************
  1.     polymorphism : - 
*****************************

1. compile time polymorphism (static binding): 
2.  run time polymorphism (dynamic binding): 

compile time polymorphism :- creating same name function with different parameters
it detect error during compilation (method overloading)

we prefer to use compiler time polymorphism :instead of runt time polymorphism as while creating proejct
compiler can detect the error and it can be fixed at same time but in run time possibilities of detecting 
errors are less 

example :-

class A
{
	public void disp()
	{
		System.out.println("Inside First disp method");
	}

	public void disp(String val)
	{
		System.out.println("Inside Second disp method, value is: "+val);
	}

	public void disp(String val1,String val2)
	{
		System.out.println("Inside Third disp method, values are : "+val1+","+val2);
	}
}
public class B
{
	public static void main (String args[])
	{
		A a = new A();
		a.disp(); //Calls the first disp method
		a.disp("Java Interview"); //Calls the second disp method
		a.disp("JavaInterview", "Point"); //Calls the third disp method
	}

}

Output

Inside First disp method
Inside Second disp method, value is: Java Interview
Inside Third disp method, values are : JavaInterview,Point

-------

run time polymorphism :- creating same name function and decision is taken during run time of 
which function call to bind to the object . (method overriding)
concept of virtual function call or using funcitono from different classes 

like this
class Parent 
{
    public void display(String name)
    {
        System.out.println("Welcome to Parent Class \""+name+"\"");
    }
    public void disp()
    {
        System.out.println("disp() method of Parent class");
    }
}
public class Child extends Parent
{
    public void display(String name)
    {
        System.out.println("Welcome to Child Class \""+name+"\"");
    }
    public void show()
    {
        System.out.println("show() method of Child class");
    }
    public static void main(String args[])
    {
        //Assign Child Object to Parent class reference
        Parent pp = new Child();
        pp.display("JIP");
     }
}

OUTPUT

Welcome to the child class "JIP".

here if the child class method doesn't override the function of parent class then the  method of 
parent class will be called directly wiithout any changes to the functionalitiy..

class Parent 
{
    public void display(String name)
    {
        System.out.println("Welcome to Parent Class \""+name+"\"");
    }
    public void disp()
    {
        System.out.println("disp() method of Parent class");
    }
}
public class Child extends Parent
{
    public void display(String name)
    {
        System.out.println("Welcome to Child Class \""+name+"\"");
    }
    public void show()
    {
         System.out.println("show() method of child class");
    }
    public static void main(String args[])
    {
        //Assign Child refernce to Parent class
        Parent pp = new Child();
        pp.show();
     }
}
When you run the above code then we will get the below compile time exception “The method show() is undefined for the type Parent”. In Dynamic Method Dispatch

The Overridden methods of the Child class can be called.
Non-Overridden methods of the Parent class can be called.
Child class methods cannot be called.


********************************
  2.      inheritance
********************************

when 2nd class want to take the property of 1st class then we use inheritance
it enhance the reusability of code 


base class - parebt class
subclass - child class 


no multiple inheritance in java but inheritance


multilevel inheritance
|
class shape
{
    String color;
    public void area()
    {
        System.out.println("display area");
    }
}

class triangle extends shape
{
public void area(int length , int height)
{
System.out.println("1/2*length*height");
}
}

class equilateraltriangle extends triangle
{
    public void area(int length, int height)
    {
        System.out.println("1/2*length*height");
    }
}

---- 
hierarchical inheritance 
----
class circle extends shape
{
    public void area(int radius)
    {
        System.out.println("3.14*radius*radius");
    }
}

public class oops
{
    public static void main(String[] args)
    {
        triangle t1 = new triangle();
        t1.color = "red";
    }
}


********************************
  3.      encapsulation
********************************

first understand packages - means collection of same thing or related coded

packages :- 

- builtin packages example (import java.util.*;)
- 
package bank ;
class account
{
    publibc string name;
}
public class bank {
public static void main(String[] args)
{
    account account1 = new account();
    account1.name = "John Smith";
    
}
}
*/