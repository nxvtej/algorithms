
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vpi vector<pair<int, int>>
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
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL); 
    }
    
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
  
    Node* get(char ch){
        return links[ch - 'a'];
    }
    bool setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;

        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }

            // moving to the next reference 
           node= node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(int i =0;i<word.length();i++){
            if(!node->containsKey(word[i])){
return false;
            }
            node= node->get(word[i]);
        }
        return node->isEnd();

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
return false;
            }
            node=node->get(prefix[i]);
        }
        return true;

    }
};

int main() {
    Trie trie;

    // Test case 1: Insert and search for a word
    trie.insert("hello");
    cout << (trie.search("hello") ? "Found 'hello'\n" : "Did not find 'hello'\n");

    // Test case 2: Search for a word that hasn't been inserted
    cout << (trie.search("world") ? "Found 'world'\n" : "Did not find 'world'\n");

    // Test case 3: Insert another word and search for it
    trie.insert("world");
    cout << (trie.search("world") ? "Found 'world'\n" : "Did not find 'world'\n");

    // Test case 4: Search for a prefix that exists
    cout << (trie.startsWith("hell") ? "Found prefix 'hell'\n" : "Did not find prefix 'hell'\n");

    // Test case 5: Search for a prefix that doesn't exist
    cout << (trie.startsWith("worlde") ? "Found prefix 'worlde'\n" : "Did not find prefix 'worlde'\n");

    return 0;
}
