/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
       ListNode* res = head;
       ListNode* cur = head; 
       int sum = head->val;

       for(cur = head->next; cur != NULL; cur = cur->next) {
           if(cur->val > 0) {
               sum += cur->val;
           } else {
               res -> val = sum;
               if(cur -> next == NULL) break;
               res = res->next;
               sum = 0;
           }
       }

       res->next = NULL;
       return head; 
    }
};
