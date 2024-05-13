/**
 * 83. 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;

        while (cur->next) {
            if (cur->val == cur->next->val) {  // 跳过当前节点
                pre->next = cur->next;
            } else {  // 节点不同，比较下一个节点
                pre = cur;
            }
            cur = cur->next;
        }

        return dummy->next;
        ;
    }
};
