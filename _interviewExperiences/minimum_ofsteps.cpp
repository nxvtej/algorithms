// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

void findMinMoves(int a, int b)
{
	int ans = 0;
	if (a == b || abs(a - b) == 1) {
		ans = a + b;
	}

	else {
		int k = min(a, b);
		int j = max(a, b);

		ans = 2 * k + 2 * (j - k) - 1;
	}
	cout << ans;
}

int main()
{
	int a = 3, b = 5;

	// Function Call
	findMinMoves(a, b);

	return 0;
}
