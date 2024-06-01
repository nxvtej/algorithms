#include <iostream>
#include <vector>
using namespace std;
/*
// extreme naive approach
int main() {
    int testcase =0;
    cin>>testcase;
    while(testcase) {
        char matrix[3][3];
        char answer;

        for(int i=0;i<3;i++) {
           cin>> matrix[0][i];
        }

        for(int i=0;i<3;i++) {
           cin>> matrix[1][i];
        }for(int i=0;i<3;i++) {
           cin>> matrix[2][i];
        }



        testcase--;
    }
    return 0;
}
*/

// lets solve this
char findchar(vector<vector<char>> &square, int row, int col)
{
    int countA=0,countB=0,countC =0;
    // char value = 'A' + 'B' + 'C' - square[row][0] - square[row][1] - square[row][2];
    if('A'==square[row][0] || 'A' == square[row][1] || 'A'==square[row][2]) {
         countA=1;
    }
    if('B'==square[row][0] || 'B' == square[row][1] || 'B'==square[row][2]) {
         countB=1;
    }
    if('C'==square[row][0] || 'C' == square[row][1] || 'C'==square[row][2]) {
         countC=1;
    }
    if(countA == 0)return 'A';
    else if(countB == 0) return 'B';
    return 'C';
    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<char>> square(3, vector<char>(3));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> square[i][j];
            }
        }
        // looking for ? in vector;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (square[i][j] == '?')
                {
                    char ans = findchar(square, i, j);
                    cout << ans << endl;
                    break;
                }
            }
        }
    }
    return 0;
}