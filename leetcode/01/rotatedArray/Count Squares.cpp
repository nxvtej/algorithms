
// many solutions
/*
starting using for loop and chekcing i*i < N

using sqrt (n-1) return value

usign binary serch

int countSquares(int N) {
    int low = 1, high = N - 1, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid * mid < N) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}




 */
/*
Count Squares
Difficulty: BasicAccuracy: 41.44%Submissions: 137K+Points: 1
Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. You are given a number N, you have to output the number of integers less than N in the sample space S.



Example 1:

Input :
N = 9
Output:
2
Explanation:
1 and 4 are the only Perfect Squares
less than 9. So, the Output is 2.
Example 2:

Input :
N = 3
Output:
1
Explanation:
1 is the only Perfect Square
less than 3. So, the Output is 1.


Your Task:
You don't need to read input or print anything. Your task is to complete the function countSquares() which takes an Integer N as input and returns the answer.



Expected Time Complexity: O(sqrt(N))
Expected Auxiliary Space: O(1)



Constraints:
1 <= N <= 108


*/