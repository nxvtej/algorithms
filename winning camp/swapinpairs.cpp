
#include <iostream>
using namespace std;
 // namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        // create dummy node to swap 
        ListNode* dummyNode = new ListNode();
        ListNode* prevNode = dummyNode;
        ListNode* currentNode = head;

        while(currentNode && currentNode->next) {
            prevNode->next = currentNode->next;
            currentNode->next = prevNode->next->next;
            prevNode->next->next = currentNode;

            prevNode=currentNode;
            currentNode=currentNode->next;
        }
        return dummyNode->next;
    }
};




// simple version
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;

        while(temp !=NULL && temp->next !=NULL ) {
            swap(temp->val, temp->next->val);
            temp=temp->next->next;
        }

        return head;
    }
};