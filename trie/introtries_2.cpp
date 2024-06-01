/*
Problem statement
Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.

1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.

2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.

3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.

4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

5) erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.
Note:

1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.

2. If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.
Can you help Ninja implement the "TRIE" data structure?
*/
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

struct Node
{
    Node *links[26];
    int cntEndsWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    Node *get(char ch)
    {
        return (links[ch - 'a']);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    void increaseEnd()
    {
        cntEndsWith++;
    }

    void increasePrefix()
    {
        cntPrefix++;
    }

    void deleteWord()
    {
        cntEndsWith--;
    }

    void reducePrefix()
    {
        cntPrefix--;
    }

    int getEnd()
    {
        return cntEndsWith;
    }
    int getPrefix()
    {
        return cntPrefix;
    }

    bool isEnd()
    {
        return cntEndsWith > 0;
    }
};
class Trie
{

    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
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
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getPrefix();
    }

    // void erase(string &word){
    //     // Write your code here.
    //     Node* node = root;
    //     for(int i=0;i<word.length();i++){
    //         if(node->containsKey(word[i])){
    //             node=node->get(word[i]);
    //             node->reducePrefix();
    //         }
    //         else return;
    //     }
    //     node->deleteWord();
    // }

    // includes removing the links
    void erase(string &word)
    {
        // Write your code here.
        Node *node = root;
        vector<Node *> path = {node};
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                path.push_back(node);
                node->reducePrefix();
            }
            else
                return;
        }

        node->deleteWord();

        // now removing liniks
        if (node->getEnd() == 0 && node->getPrefix() == 0)
        {
            for (int i = path.size() - 2; i >= 0; i--)
            {
                path[i]->links[word[i] - 'a'] = nullptr;
                if (path[i]->getEnd() > 0 || path[i]->getPrefix() > 0)
                {
                    break;
                }
            }
        }
    }

    void printTrie(Node *node, string word = "")
    {
        if (node->isEnd())
        {
            cout << word << endl;
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            Node *nextNode = node->get(ch);
            if (nextNode != NULL)
            {
                printTrie(nextNode, word + ch);
            }
        }
    }

    void printTrie()
    {
        printTrie(root, "");
    }
};

// int main()
// {
//     Trie trie;

//     // Test case 1: Insert and search for a word
//     trie.insert("hello");
//     cout << trie.countWordsEqualTo("hello") << endl; // Output: 1

//     // Test case 2: Erase a word and search for it
//     trie.erase("hello");
//     cout << trie.countWordsEqualTo("hello") << endl; // Output: 0

//     // Test case 3: Insert multiple words with the same prefix and count them
//     trie.insert("tree");
//     trie.insert("trie");
//     trie.insert("trip");
//     cout << trie.countWordsStartingWith("tr") << endl; // Output: 3

//     // Test case 4: Erase a word and count words with the same prefix
//     trie.erase("trie");
//     cout << trie.countWordsStartingWith("tr") << endl; // Output: 2

//     // Test case 5: Erase a non-existent word
//     trie.erase("trie");
//     cout << trie.countWordsStartingWith("tr") << endl; // Output: 2

//     // pritingng

//     trie.insert("hello");
//     trie.insert("world");
//     trie.insert("trie");
//     trie.insert("tree");
//     trie.insert("trial");

//     // Print the entire Trie
//     cout << "Trie contents:\n";
//     trie.printTrie();
//     return 0;
// }

// const error fixed
// now using vairbles
int main()
{
    Trie trie;

    // Test case 1: Insert and search for a word
    string word1 = "hello";
    trie.insert(word1);
    cout << trie.countWordsEqualTo(word1) << endl; // Output: 1

    // Test case 2: Erase a word and search for it
    trie.erase(word1);
    cout << trie.countWordsEqualTo(word1) << endl; // Output: 0

    // Test case 3: Insert multiple words with the same prefix and count them
    string word2 = "tree";
    string word3 = "trie";
    string word4 = "trip";
    trie.insert(word2);
    trie.insert(word3);
    trie.insert(word4);
    string prefix = "tr";
    cout << trie.countWordsStartingWith(prefix) << endl; // Output: 3

    // Test case 4: Erase a word and count words with the same prefix
    trie.erase(word3);
    cout << trie.countWordsStartingWith(prefix) << endl; // Output: 2

    // Test case 5: Erase a non-existent word
    trie.erase(word3);
    cout << trie.countWordsStartingWith(prefix) << endl; // Output: 2

    // pritingng

    trie.insert(word1);
    string word5 = "world";
    trie.insert(word5);
    trie.insert(word3);
    trie.insert(word2);
    string word6 = "trial";
    trie.insert(word6);

    // Print the entire Trie
    cout << "Trie contents:\n";
    trie.printTrie();
    return 0;
}
