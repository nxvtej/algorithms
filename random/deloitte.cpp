#include <iostream>
using namespace std;

int findpos(int arr[], int n)
{
    int leftSum = 0;
    int totalSum = 0;

    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }

    for (int i = 0; i < n; i++)
    {

        if (leftSum == totalSum - leftSum - arr[i])
        {
            return i;
        }
        leftSum += arr[i];
    }
    return -1;
}

int findSum(int arr[], int position)
{
}
void question1()
{
    int arr[] = {1, 2, 2, 5, 9, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int position = findpos(arr, n);
    int output = arr[position];
    cout << position + 1 << " ";
    cout << "Sum is:" << findSum(arr, position);
    return;
}

void question2()
{
}

int main()
{

    int choice = 0;
    cout << "question 1\nquestion 2\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        question1();
        break;
    case 2:
        question2();
        break;
    default:
        cout << "wrong choice\nexit";
    }
    return 0;
}