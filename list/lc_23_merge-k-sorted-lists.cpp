/** 
 * 23. 合并K个升序链表
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/
 */

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL;
        for(int i = 0; i < lists.size(); i++) {
            ans = mergeTwoLists(ans, lists[i]);
        }

        return ans;
    }

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        ListNode* aPtr = a, *bPtr = b;

        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; 
                aPtr = aPtr->next;
            } else {
                tail->next = bPtr; 
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }

        tail->next = (aPtr ? aPtr : bPtr);
        ListNode* h = head->next;
        delete head;

        return h;
    }
};
