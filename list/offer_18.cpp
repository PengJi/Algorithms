/**
 * 剑指 Offer 18. 删除链表的节点
 * https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val) return head->next;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur != NULL && cur->val != val) {
            pre = cur;
            cur = cur->next;
        }

        if(cur != NULL) pre->next = cur->next;
        return head;
    }
};
