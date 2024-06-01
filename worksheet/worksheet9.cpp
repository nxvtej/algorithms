/*
Demonstrate the concept of dynamic
memory allocation for 1-D array 
within the class with data members
float *arr and int size. 
Make use of default 
constructor, parameterized constructor
and destructor for the same. 
*/
/*
#include <iostream>
#include <math.h>
using namespace std;

class thread
{
    private :
    float *arr;
    int size;

    public :
    class Error {};
    thread()
    {}

    thread(int size)
    {
        this->size = size;
        arr = new float[size];

    }

    void values ()
    {
        cout<<"enter values"<<endl;
        for(int i=0; i<size; i++)
        {
            cin>>arr[i];
        }
        if((arr == NULL) || (sizeof(arr)/sizeof(arr[0]) )> size)
        {
            throw Error();
        }
    }
    
    ~thread() 
    {
        delete[] arr;
    }
};

int main(int argc, char** argv)
{

    cout<<"enter size of array"<<endl;
    int size{};
    cin>>size;

    thread objects(size);
    try
    {
        
        objects.values();
    }
    catch(thread :: Error)
    {
        std::cerr << "error encountered " << '\n';
    }
    cout<<"values saved\n";

}
*/
/*
Demonstrate the concept of dynamic memory allocation for 2-D array within 
the class with data members float **arr ,int rowsize and int colsize. Make 
use of default constructor, parameterized constructor and destructor for 
the same
*/
/*
#include <iostream>
#include <math.h>
using namespace std;

class thread
{
    private :
    float **arr;
    int rowsize , columnsize ;

    public :
    class Error {};
    thread()
    {}

    thread(int rowsize , int columnsize)
    {
        this->rowsize = rowsize;
        this->columnsize = columnsize;

        arr = new float*[rowsize];
        for(int i = 0; i < rowsize; i++)
        arr[i] = new float[columnsize];
    }

    void values ()
    {
        cout<<"enter values"<<endl;

        for(int i=0; i<rowsize; i++)
        {
            for(int j=0; j<columnsize; j++)
            cin>>*(*(arr+i)+j);
        }
        if((arr == NULL) || (sizeof(arr)/sizeof(arr[0]) )> rowsize*columnsize)
        {
            throw Error();
        }
    }
    
    ~thread() 
    {
        for(int i = 0; i < rowsize; i++)
        delete[] arr[i];
        delete []arr;
    }
};

int main(int argc, char** argv)
{

    cout<<"enter rowsize of array"<<endl;
    int rowsize{};
    cin>>rowsize;

    cout<<"enter columnsize of array"<<endl;
    int columnsize{};
    cin>>columnsize;
    thread objects(rowsize , columnsize);
    try
    {
        
        objects.values();
    }
    catch(thread :: Error)
    {
        std::cerr << "error encountered " << '\n';
    }
    cout<<"values saved\n";

}

*/

#include <iostream>
 using namespace std;
 class array {
     float *arr;
     int size;
     public:
     array()
     {}
     array(int s)
     {
 size=s;
         arr=new float[size];
     }
 ~array() {
 delete arr; }
     void print();
     void show();
 };
 void array::print()
 {
     for(int i=0;i<size;i++)
 cin>>arr[i];
 }
 void array::show()
 {
     for(int i=0;i<size;i++)
     cout<<arr[i]<<endl;
 }
 int main() {
     int size;
     cout<<"Enter size of the array : ";
     cin>>size;
     array obj(size);
     cout<<"Enter elements :";
     obj.print();
     cout<<"Elements you have entered :";
     obj.show();
 return 0; }
