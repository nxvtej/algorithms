#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
 class Solution
{
private:
    Node *solve(Node *head)
    {
        // check if something exists for cycle or not
        if (head == NULL || !head->next)
            return NULL;

        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (slow != fast)
            return NULL;

        // now both are at the meting point for sure
        slow = head;

        while (slow != fast)
        {
            slow = head->next;
            fast = fast->next;
        }

        return slow;
    }

public:
    Node *detectCycle(Node *head)
    {
        int t;
        cin >> t;
        while (t--)
        {
            int n;
            cin >> n;

            vector<int> nodelist(n);
            int cyclestartingindex;

            // taking input for data;
            for (int i = 0; i < n; i++)
            {
                cin >> nodelist[i];
            }
            cin >> cyclestartingindex;

            // to create linked list now i need to create nodelist
            Node *current = head;
            Node *cycleStart = nullptr;

            // put vector values into the head;
            for (int i = 0; i < n; i++)
            {
                int values = nodelist[i];

                Node *newNode = new Node(values);

                if (!head)
                {
                    head = newNode;
                    current = head;
                }
                else
                {
                    current->next = newNode;
                    current = newNode;
                }

                // if its the index hwere cycle starts then save the nodelist
                if (i == cyclestartingindex)
                {
                    cycleStart = newNode;
                }
            }
            // now get the starting point of the linkedlsit
            Node *result = solve(head);
            return result;
        }
    }
};