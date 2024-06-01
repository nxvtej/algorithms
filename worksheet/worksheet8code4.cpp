#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    long long memlimit = 0x14ffffffffffffffff;
    try
    {
        
        int * disko = new int[memlimit];

        cout<<"chlna to nhi chahiye thaa : \n lekin koi ni";
        cout<<"memory llocated\n";
    }
    catch(const bad_alloc& memory)
    {
        std::cerr<<" error nhi chahiye thaa " << memory.what() << '\n';
    }

    return 0;
}