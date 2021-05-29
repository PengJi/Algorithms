/**
 * 83. 删除排序链表中的重复元素
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
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
    // 遍历
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* cur = head;

        while(cur->next) {
            if(cur->val == cur->next->val) {
                pre->next = cur->next;
                cur = cur->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }

        ListNode* node = dummy->next;
        delete  dummy;
        return node;
    }
};
