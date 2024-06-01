/*Run-Time Polymorphism: 
Whenever an object is bound with the functionality at
run time, this is known as runtime polymorphism
. The runtime polymorphism can be achieved by method overriding.
*/

/*
run time polymorphism is when we the object is being overridden
and the execution of function is being */

    #include <iostream>    
    using namespace std;    
    class a {    
        public:    
    virtual void aa(){      
    cout<<"runnig ion the base class a aa.";      
        }        
    };     
    class b: public a     
    {      
     public:    
     void aa()      
        {           cout<<"running in the class b  aa...";      
        }      
    };    
    int main(void) {    
       a *ptra;
       b objb;

       ptra = &objb; 

       ptra->aa();
       return 0;    
    } 