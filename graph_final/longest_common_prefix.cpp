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

/*
simple method using loop
*/

/*
string longest_common_prefix(vs &arr, int n)
{
    sort(arr.begin(), arr.end());
    int i = 0, j = 0;
    string string_1 = arr[0], string_2 = arr[n - 1], ans = "";
    while (string_1[i] == string_2[j])
    {
        ans += string_1[i];
        i++;
        j++;
    }
    return ans;
}
int main()
{
    // Create a vector of strings
    vs words = {"flower", "flow", "flight"};

    // Call the longest_common_prefix function
    string lcp = longest_common_prefix(words, words.size());

    // Print the result
    cout << "Longest common prefix: " << lcp << endl;

    return 0;
}
*/

// another method using trie
struct Node
{
    Node *links[26];
    bool isEnd = false;
    int cntPrefix = 0;
    Node()
    {
        isEnd = false;
        cntPrefix = 0;
        for (int i = 0; i < 26; i++)
        {
            links[i] = NULL;
        }
    }

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
};

void insert(string &word, Node *root)
{
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
        if (!node->containsKey(word[i]))
        {
            node->put(word[i], new Node());
        }
        node = node->get(word[i]);
        node->increasePrefix();
    }
    node->isEnd = true;
}

/*
for testing the insert fucniton using print funcitons
*/
void _print_trie(Node *root, string word = "")
{
    if (root->isEnd)
        cout << word << endl;

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (root->containsKey(ch))
        {
            Node *newNode = root->get(ch);
            _print_trie(newNode, word + ch);
        }
    }
}
void print_trie(Node *root)
{
    _print_trie(root, "");
}
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Node *root = new Node;

    for (auto it : arr)
    {
        insert(it, root);
    }

    print_trie(root);

    // after insertion now checking for the longest common prefix;
    // starting
    return " ";
}
int main()
{
    vector<string> words = {"flower", "flow", "flight"};
    cout << "Longest common prefix: " << longestCommonPrefix(words, words.size()) << endl;
    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    int countPrefix;

    TrieNode() {
        isEndOfWord = false;
        countPrefix = 0;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (node->children[ch - 'a'] == NULL) {
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
            node->countPrefix++;
        }
        node->isEndOfWord = true;
    }

    string longestCommonPrefix() {
        TrieNode* node = root;
        string prefix = "";
        while (countChildren(node) == 1 && !node->isEndOfWord) {
            int index = maxChildIndex(node);
            prefix += 'a' + index;
            node = node->children[index];
        }
        return prefix;
    }

private:
    int countChildren(TrieNode* node) {
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL) {
                count++;
            }
        }
        return count;
    }

    int maxChildIndex(TrieNode* node) {
        int maxIndex = 0;
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL &&
                node->children[i]->countPrefix > node->children[maxIndex]->countPrefix) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }
};

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    Trie trie;
    for (const string& word : strs) {
        trie.insert(word);
    }

    return trie.longestCommonPrefix();
}

int main() {
    vector<string> words = {"flower", "flow", "flight"};
    cout << "Longest common prefix: " << longestCommonPrefix(words) << endl;
    return 0;
}
*/