/**
 * 82. 删除排序链表中的重复元素 II
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur;

        while (pre->next) {
            cur = pre->next;
            while (cur && cur->val == pre->next->val) cur = cur->next;

            if (pre->next->next == cur) {  // 没有重复
                pre = pre->next;
            } else {  // 重复，删除重复节点
                pre->next = cur;
            }
        }

        return dummy->next;
    }
};
