#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int value;

        Node *prev;
        Node *next;
        Node(int _key, int _value)
        {
            key = _key;
            value = _value;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int capacity, count = 0;
    unordered_map<int, Node *> mpp;

    LRUCache(int capacity)
    {
        this->capacity = capacity;

        head->next = tail;
        tail->prev = head;

        head->prev = nullptr;
        tail->next = nullptr;
    }
    void deleteNode(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        return;
    }

    void addToHead(Node *node)
    {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;

        head->next = node;

        return;
    }
    int get(int key)
    {
        if (mpp[key] != nullptr)
        {
            Node *node = mpp[key];
            int value = node->value;

            deleteNode(node);
            addToHead(node);
            return value;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (mpp[key] != nullptr)
        {
            Node *node = mpp[key];
            node->value = value;

            deleteNode(node);
            addToHead(node);
        }
        else
        {
            Node *node = new Node(key, value);
            mpp[key] = node;

            if (count < capacity)
            {
                count++;
                addToHead(node);
            }
            else
            {

                mpp[tail->prev->key] = NULL;
                deleteNode(tail->prev);

                addToHead(node);
            }
        }

        return;
    }
};
