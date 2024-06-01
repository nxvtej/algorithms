#include <iostream>
using namespace std;

int main()
{
    
    /*
    int size = 0,printable = 65 , i = 1;

    cout<<"size\n5";
    size=5;
    cout<<endl;

    char ch='A';
    while (i < size)
    {
        int j = 1;

        while(j<=i)
        {
            ch = 'A'+ j + i - 2 ;
            cout<<ch<<" ";
            j++;

            /*
A
B C 
C D E
D E F G
*//*


        }

        ch ='A'+i;
        cout<<endl;
        i++;
        
    }
    */
/*
   int i = 1 ,n , j =1;
   cin>>n;
   while (i<=n)
   {
    
    char start = 'A' + n - j;
    j = 1;
    while (j<=i)
    {
        cout<<start<<" ";
        start = start + 1;
        j++;

// 5
// E
// D E
// C D E
// B C D E
// A B C D E
    }
    cout<<endl;
    i++;
   }
   
   */

/*  
int i = 1 , n= 0;
  cin>>n;

  while (i<=n)
  {
    int spaces = n-i;

    while (spaces)
    {
        cout<<" ";
        spaces--;
    }
    int temp = i;
    while (temp)
    {
        cout<<"*";
        temp--;
    }
cout<<endl;
    i++;

//     5
//     *
//    **
//   ***
//  ****
// *****
    
  }
  */

/*
int n = 0 ;
cin>>n;

int i = n;
while(i)
{
    int j = 1;
    while(j<=i)
    {
        cout<<"* ";
        j++;
    }
    cout<<endl;
    i--;
//     5
// * * * * * 
// * * * * 
// * * * 
// * * 
// * 
}
*/

/*
int n = 0;
cin>>n;
int row  = 1;
while (row <= n)
{
    int spaces = row - 1;
    while (spaces)
    {
        cout<<" ";
        spaces--;
    }

    int col = row;
    while (col<=n)
    {
        cout<<col;
        col++;
    }
    
    
    cout<<endl;
    row++;
}

// 5
// 12345
//  2345
//   345
//    45
//     5
*/


int n = 0 ;
cin>>n;

int row = 1 , col = 1;

while(row<=n)
{
    int spaces = n-1;
    while (spaces)
    {
        cout<<" ";
        spaces--;
    }

    while (col<=row)
    {
        cout<<col;
        col++;
    }

    int temp = row; 
    while (col>=row)
    {
        cout<<col;
        col--;
    }

    cout<<endl;
    row++;
    
    
    
}
}


