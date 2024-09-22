#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

void extraLongFactorials(int n)
{
    boost::multiprecision::cpp_int factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial *= i;
    }
    cout << factorial << endl;
}

int main()
{
    int n;
    cin >> n;

    extraLongFactorials(n);

    return 0;
}