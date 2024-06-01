/*
WAP that throws an exception raised when memory is not allocated for the 2d array.
in case the exception is not handled then define your own program to terminate the programme.
*/
#include <iostream>
using namespace std;

int main( void )

{
    cout<<"enter the size for the 2d array"<<endl;
    int row , column;
    cin>>row>>column;

    try
    {
        int **array = new int*[row] ;

        for( int i=0 ; i<row ; i++)
        array[i] = new int[column];
    }
    catch(const bad_alloc & memory)
    {
        std::cerr << "BHAISHAB memory allocation error aagya" << '\n';
    }
}


/*
WAP that throws a named class object when an out of bound exception is raised , the program also 
throws an exception when the number of elements in the array are either less than 0
or greater than MAX . in case the exception is not handled then define your own program to 
terminate the program . 
*/
/*
class evaluation_code2
{
    private :
    int *array ;
    int size{} ;

    public :

    class evaluation_code_error{};
    evaluation_code2(){};
    evaluation_code2(int size)
    {
        this->size = size;
        array = new int[size];
    }

    void get_array()
    {
        
        cout<<"enter the array values\n";
        for(int i=0; i<size;i++)
        {
            cin>>array[i];
        }

    }
};
void disko()
{
    cout<<"my terminate is being called by set_terminate\n";
    cout<<"calling the inbuilt function abort()\n";
    abort();
}

int main(void)
{
    set_terminate(disko);    
    try
    {
        int size;
        cout<<"enter the size of the array\n";
        cin>>size;
        if(size<0 || size>1000000000)
        throw "invalid";
        evaluation_code2 object(size);
        object.get_array();

    }
    catch(...)
    {
        std::cerr << " BHAISHAB ye to error hai" << '\n';
    }
}*/