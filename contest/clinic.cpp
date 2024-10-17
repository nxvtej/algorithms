#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T; // Number of test cases
    while (T--)
    {
        int N, X;
        cin >> N >> X; // Size of the array and parameter
        vector<int> B(N);

        // Read the difficulties
        for (int i = 0; i < N; i++)
        {
            cin >> B[i];
        }

        // Result array for final difficulties
        vector<int> C(N);
        C[0] = B[0]; // Set the first difficulty directly

        // Calculate the balanced contest difficulties
        for (int i = 1; i < N; i++)
        {
            // The next difficulty should be within B[i] + X and C[i-1] + X
            C[i] = max(C[i - 1], B[i] - X); // Ensure non-decreasing order
            C[i] = min(C[i], B[i] + X);     // Ensure we don't go over B[i] + X
        }

        // Calculate the cost K
        int K = 0;
        for (int i = 0; i < N; i++)
        {
            K = max(K, abs(C[i] - B[i]));
        }

        // Output the minimum cost and the adjusted difficulties
        cout << K << endl;
        for (int i = 0; i < N; i++)
        {
            cout << C[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
