
#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // create dummy nodes and save them for pointers use

        ListNode* leftdummy = new ListNode(0);
        ListNode* left = leftdummy;
        ListNode* rightdummy = new ListNode(0);
        ListNode* right = rightdummy;

        while(head) {
            if(head->val < x) {
                left->next = head;
                left= left->next;
            }

            else {
                right->next = head;
                right= right->next;
            }

            head = head->next;
        }

        // now connect those two lists;
        left->next = rightdummy->next;
        right->next = nullptr;
        return leftdummy->next;
    }
};