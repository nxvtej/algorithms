#include<iostream>
using namespace std;

int main()
{
    // Number Pyramid Pattern
    cout << endl;
    cout << "You are going to see a number pyramid pattern:- " << endl;

    int height, i, j, k, l;
    cout << endl;
    cout << "Enter height of the pyramid:- ";
    cout << endl;
    cin >> height;
    cout << endl;

    for (i = 1; i <= height; i++)
    {
        for (k = 1; k <= (height - i); k++)
        {
            cout << "  ";
        }
        for (j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        for (l = i - 1; l >= 1; l--)
        {
            cout << l << " ";
        }
        cout << endl;
    }
    
    /*
    int temp = n;

    int row = 1;
    while(row<=n)
    {
        int j = temp;
        while(j>=1)
        {
            cout<<j<<" ";
            j--;
        }
        temp--;
        cout<<endl;
        row++;  
    }
    */
}