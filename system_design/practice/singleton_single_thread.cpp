#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;
class singleton
{
public:
    static singleton *instance;
    singleton()
    {
        cout << "Constructor called" << endl;
    }

    static singleton *getsingletonInstance()
    {
        // use locks
        if (instance == nullptr)
        {
            mtx.lock();

            if (instance == nullptr)
            {
                instance = new singleton();
            }

            mtx.unlock();
        }
        return instance;
    }
};

void thread1()
{
    singleton *firstInstance = singleton::getsingletonInstance();
    cout << "Thread 1: " << firstInstance << endl;
}

void thread2()
{
    // mtx.lock()
    // individual lock to get correct ouput like thread1 vanswer, thread2 answer
    singleton *secondInstance = singleton::getsingletonInstance();
    cout << "Thread 2: " << secondInstance << endl;
}

singleton *singleton::instance = nullptr;
int main()
{
    /*
     singleton *firstInstance = singleton::getsingletonInstance();
     singleton *secondInstance = singleton::getsingletonInstance();
 */
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    /*
singleton firstInstance;
singleton secondInstance;


    if (firstInstance == secondInstance)
        cout << "yeah it works\n";
    else
        cout << "nope wrong way!!";
*/
    return 0;
}