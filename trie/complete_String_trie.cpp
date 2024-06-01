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

#include <bits/stdc++.h>

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkifPrefixExists(string &word)
    {
        bool fl = true;
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                fl = fl & node->isEnd();
            }
            else
                return false;
        }

        return fl;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie trie;
    for (auto &it : a)
    {
        trie.insert(it);
    }

    // nexyt step
    string longest = "";

    for (auto &it : a)
    {
        if (trie.checkifPrefixExists(it))
        {
            if (it.length() > longest.length())
            {
                longest = it;
            }
            else if (it.length() == longest.length() && it < longest)
            {
                longest = it;
            }
        }
    }
    if (longest == "")
        return "None";
    return longest;
}
int main()
{
    vs words = {"f", "fl", "flo", "flower", "flow", "flight"};
    int n = words.size();
    cout << "Longest common prefix: " << completeString(n, words) << endl;
    return 0;
}
