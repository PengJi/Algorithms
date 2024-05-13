/**
 * 24. 两两交换链表中的节点
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* tmp;  // 存储当前组的下一个节点

        while (cur && cur->next) {
            tmp = cur->next->next;
            pre->next = cur->next;
            cur->next->next = cur;
            cur->next = tmp;

            pre = cur;
            cur = cur->next;
        }

        return dummy->next;
    }
};
