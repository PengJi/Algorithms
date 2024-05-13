/**
 * 剑指 Offer 25. 合并两个排序的链表
 * https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
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
    // 时间复杂度：O(m + n)
    // 空间复杂度：O(1)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pre = new ListNode(0);
        ListNode* cur = pre;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        cur->next = l1 != NULL ? l1 : l2;
        return pre->next;
    }
};
