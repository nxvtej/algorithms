/*
Problem statement
Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. You should implement the program using a trie.

Note :
A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) from the start of ‘A’ and several characters(possibly none) from the end of ‘A’. 

Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’  such that the character of ‘X’ at index ‘i’ is different from the character of ‘Y’ at index ‘i’(X[i]!=Y[i]).
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 5
1 <= |S| <= 10^3

‘S’ contains only lowercase English letters.

Time Limit: 1 sec
Sample Input 1 :
2
sds
abc
Sample Output 1 :
6
7
Explanation of Sample Input 1 :
In the first test case, the 6 distinct substrings are { ‘s’,’ d’, ”sd”, ”ds”, ”sds”, “” }

In the second test case, the 7 distinct substrings are {‘a’, ‘b’, ‘c’, “ab”, “bc”, “abc”, “” }.
Sample Input 2 :
2
aa
abab
Sample Output 2 :
3
8
Explanation of Sample Input 2 :
In the first test case, the two distinct substrings are {‘a’, “aa”, “” }.

In the second test case, the seven distinct substrings are {‘a’, ‘b’, “ab”, “ba”, “aba”, “bab”, “abab”, “” }


Hints:
1. Can you think about a data structure that can be used to store the distinct substrings?
2. Can you think about using the fact that every substring of ‘S’ is a prefix of some suffix string of ‘S’?
3. Try to insert every suffix of the string in Trie.
*/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vpi vector<pair<int, int>>
#define vs vector<string>
// #define via vector<int> []
#define qi queue<int>
#define qp queue<pair<int, int>>
#define qpf queue<pair<pair<int, int>, int>>

#define si set<int>
#define sii set<pair<int, int>>
#define sp set<pair<int, int>>
#define svii set<vector<pair<int, int>>>

#define pb push_back
#define ff front().first
#define fff front().first.first
#define ffs front().first.second
#define fs front().second

struct Node {
    Node* links[26];
    bool containsKey(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};


int countDistinctSubstrings(string &word)
{
    //    Write your code here.
     int cnt=0;
     Node* root= new Node();
     for(int i=0;i<word.size();i++){
         Node* node = root;
         for(int j =i;j<word.size();j++){
             if(!node->containsKey(word[j])){
                 cnt++;
                 node->put(word[j], new Node());
             }
             node= node->get(word[j]);
             
         }
     }
     return cnt+1;
     
}

int main() {
    string words[] = {"abcabc", "aaaaa", "abcd", "abababab"};
    for(int i = 0; i < 4; i++) {
        cout << "Number of distinct substrings in " << words[i] << " is " << countDistinctSubstrings(words[i]) << endl;
    }
    return 0;
}
