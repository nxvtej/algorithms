#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// now lets play with the no of students 
// along with their max capacity to hold book which si the mid of the range

int countStudent(vector<int> & arr, int mid) {
    int student =1;
    long long pagesStudent = 0;
    
    for(int i =0; i<arr.size(); i++ ) {
        if(pagesStudent+arr[i] <= mid) {
            pagesStudent+= arr[i];
}
        else {
            student++;
            pagesStudent = arr[i];
        }
    }
    return student;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    // approach is focuing on the range of pafges

// range can start from the max of array and in worst case it can go uptio 
// tota;l sum of all the pages of all books in case ther ei sonly one studne4t

if(n<m) return -1;

// check the low of the range which is the max iof the array
 int low = *max_element(arr.begin(), arr.end());
 int high = accumulate(arr.begin(), arr.end(), 0);
  
  while( low <=high) {
      int mid = (low+high) / 2;
      int students = countStudent(arr, mid);
      if(students > m ) {
          low = mid+1;
      }
      else {
          high = mid-1;
      }
  }
  return low;
}