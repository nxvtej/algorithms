#include <bits/stdc++.h>
using namespace std;
int main()
{

int a = 10;
int* p;
p = &a;

printf("%d\n", *p);        // p is 2002
int size = sizeof(int);
cout<<size;
// printf(sizeof(int));      // size of integer is 4
printf("\n%d\n", p+1);  

return 0;
}