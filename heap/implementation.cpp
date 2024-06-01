#include <iostream>
using namespace std;

// class heap
// {
// private:
//     int arr[100];
//     int size;

//     static int parent(int idx) { return idx / 2; }
//     static void swap(int &a, int &b)
//     {
//         int temp = a;
//         a = b;
//         b = temp;
//     }

// public:
//     heap()
//     {
//         size = 0;
//         arr[0] = -1;
//     }

//     void insert(int val)
//     {
//         size++;
//         int index = size;
//         arr[index] = val;

//         while (index > 1)
//         {
//             int par = parent(index);
//             if (arr[par] < arr[index])
//             {
//                 swap(arr[par], arr[index]);
//                 index = par;
//             }
//             else
//             {
//                 return;
//             }
//         }
//     }

//     void print()
//     {
//         for (int i = 1; i <= size; i++)
//         {
//             cout << arr[i] << " ";
//         }
//     }

//     // same goes for deletion just remove arr[1] and replace with arr[size] then take the root to its
// correct position by swapping
// };

void heapify(int arr[], int size, int index)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left < size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < size && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
    return;
}

int main()
{
    // heap h;
    // h.insert(50);
    // h.insert(300);
    // h.insert(20);
    // h.insert(35);
    // h.insert(10);
    // h.insert(-8);

    // h.print();
    cout << "\nheapyfiy\n";

    int arr[8] = {-1, 10, 5, 154, 166, 546, 56};
    heapify(arr, 8, 1);
    int n = 7;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}