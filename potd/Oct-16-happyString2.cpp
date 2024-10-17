

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef pair<int, char> P;
    string reorganizeString(string s)
    {
        int size = s.length();
        vector<int> count(26, 0);

        int maxfreq = 0;
        char maxfreqchar;
        for (auto ch : s)
        {
            count[ch - 'a']++;

            if (count[ch - 'a'] > maxfreq)
            {
                maxfreq = count[ch - 'a'];
                maxfreqchar = ch;
            }
        }

        if (maxfreq > (size + 1) / 2)
            return "";

        string answer(size, ' ');
        int index = 0;
        while (count[maxfreqchar - 'a'] > 0)
        {
            answer[index] = maxfreqchar;
            count[maxfreqchar - 'a']--;
            index += 2;
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {

            while (count[ch - 'a'] > 0)
            {
                if (index >= size)
                {
                    index = 1;
                }

                answer[index] = ch;
                index += 2;
                count[ch - 'a']--;
            }
        }

        return answer;
    }
};
/*
class Solution {
public:
    typedef pair<int, char> P;
    string reorganizeString(string s) {
        // step 1: get count of alll character
        // store in macheadp
        // run untiel the size is less than 2

        vector<int> count(26,0);
        int size=s.length();
        for(int i=0;i<size;i++){
            count[s[i]-'a']++;

            if(count[s[i] - 'a'] > ((size+1)/2)) return "";
        }
        priority_queue<P, vector<P>> maxHeap;

        for(char ch = 'a'; ch<='z';ch++){
            if(count[ch - 'a'] > 0){
                maxHeap.push(make_pair(count[ch-'a'], ch));
            }
        }


        string answer = "";
        while(maxHeap.size() >= 2){

            int firstCount = maxHeap.top().first;
            char firstCh   = maxHeap.top().second;
            maxHeap.pop();

            int secondCount = maxHeap.top().first;
            char secondCh   = maxHeap.top().second;
            maxHeap.pop();

            answer.push_back(firstCh); firstCount--;
            answer.push_back(secondCh); secondCount--;

            if(firstCount > 0) maxHeap.push(make_pair(firstCount, firstCh));
            if(secondCount > 0) maxHeap.push(make_pair(secondCount, secondCh));



        }

        if(!maxHeap.empty()){
            answer.push_back(maxHeap.top().second);
        }
        return answer;
    }
};

*/
/*
class Solution {
public:
    typedef pair<int, char> P;
    string reorganizeString(string s) {
        // same sort of question
        map<char, int> mapping;
        for (char ch : s) {
            mapping[ch]++;
        }

        vector<P> vec;
        for (auto value : mapping) {
            vec.push_back({value.second, value.first});
        }

        string answer = "";
        sort(vec.begin(), vec.end(), greater<P>());
        if (vec.size())
            answer.push_back(vec[0].second);
        vec[0].first--;

        for (int i = 1; i < s.length(); i++) {
            sort(vec.begin(), vec.end(), greater<P>());

            if (answer[i - 1] != vec[0].second){
                answer.push_back(vec[0].second);
                vec[0].first--;
            } else {
                if(vec.size() == 1 || vec[1].first <= 0){
                    return "";
                } else {
                    answer.push_back(vec[1].second);
                    vec[1].first--;
                }
            }
        }

        return answer;
    }
};*/
/*
class Solution {
public:
    typedef pair<int, char> P;
    string reorganizeString(string s) {
        // same sort of question
        map<char, int> mapping;
        for (char ch : s) {
            mapping[ch]++;
        }

        vector<P> vec;
        for (auto value : mapping) {
            vec.push_back({value.second, value.first});
        }

        string answer = "";
        sort(vec.begin(), vec.end(), greater<P>());
        if (vec.size())
            answer.push_back(vec[0].second);
        vec[0].first--;

        for (int i = 1; i < s.length(); i++) {
            sort(vec.begin(), vec.end(), greater<P>());

            if (answer[i - 1] != vec[0].second){
                answer.push_back(vec[0].second);
                vec[0].first--;
            } else {
                if(vec.size() == 1 || vec[1].first <= 0){
                    return "";
                } else {
                    answer.push_back(vec[1].second);
                    vec[1].first--;
                }
            }
        }

        return answer;
    }
};*/
/*
767. Reorganize String
Solved
Medium
Topics
Companies
Hint
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.



Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""


Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/