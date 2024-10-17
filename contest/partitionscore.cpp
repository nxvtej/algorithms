#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    int t = 0;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        //        int mid = (n+n-1)/2;
        int sum = 0;
        if (m == 1)
        {

            sum = arr[0] + arr[arr.size() - 1] + arr[arr.size() - 1] + arr[arr.size() - 2];
            cout << sum << "\n";

            continue;
        }
        sum = arr[0] + arr[arr.size() - 1] + arr[arr.size() - 2] + arr[arr.size() - m - 1];
        cout << sum << endl;
    }
}
/*
Partition Score
Given an array
A
A of size
N
N, we must partition the array into
2
2 disjoint subsets
S
1
S
1
​
  and
S
2
S
2
​
  such that every element of
A
A belongs to either
S
1
S
1
​
  or
S
2
S
2
​
 . Further, we are given a parameter
K
K and must ensure
∣
S
1
∣
≥
K
∣S
1
​
 ∣≥K and
∣
S
2
∣
≥
K
∣S
2
​
 ∣≥K, i.e. both
S
1
S
1
​
  and
S
2
S
2
​
  have size at least
K
K.

We define
s
c
o
r
e
=
min
⁡
(
S
1
)
+
max
⁡
(
S
1
)
+
min
⁡
(
S
2
)
+
max
⁡
(
S
2
)
score=min(S
1
​
 )+max(S
1
​
 )+min(S
2
​
 )+max(S
2
​
 ), where
min
⁡
(
S
1
)
min(S
1
​
 ) is the minimum element present in
S
1
S
1
​
 , and the other terms are defined similarly.

Compute the maximum
s
c
o
r
e
score in any valid partition.

Input Format
The first line of input will contain a single integer
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line contains
N
N and
K
K - the size of the array and the parameter
The next line contains
N
N integers -
A
1
,
A
2
,
.
.
.
,
A
N
A
1
​
 ,A
2
​
 ,...,A
N
​
 .
Output Format
For each test case, output on a new line the maximum
s
c
o
r
e
score in any valid partition.

Constraints
1
≤
T
≤
1
0
4
1≤T≤10
4

2
≤
N
≤
2
⋅
1
0
5
2≤N≤2⋅10
5

1
≤
K
1≤K and
2
⋅
K
≤
N
2⋅K≤N
1
≤
A
i
≤
1
0
6
1≤A
i
​
 ≤10
6

The sum of
N
N over all test cases does not exceed
2
⋅
1
0
5
2⋅10
5

Sample 1:
Input
Output
3
4 1
3 1 2 5
6 3
1 2 3 4 5 6
5 2
1000000 1000000 1000000 1000000 1000000
14
15
4000000
Explanation:
Test Case 1 : The optimum partition is :

S
1
=
[
1
,
2
,
3
]
S
1
​
 =[1,2,3]
S
2
=
[
5
]
S
2
​
 =[5]
m
i
n
(
S
1
)
=
1
min(S
1
​
 )=1,
m
a
x
(
S
1
)
=
3
max(S
1
​
 )=3,
m
i
n
(
S
2
)
=
5
min(S
2
​
 )=5,
m
a
x
(
S
2
)
=
5
max(S
2
​
 )=5. Adding them up, we get 14
*/