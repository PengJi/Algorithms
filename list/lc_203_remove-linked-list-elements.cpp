/**
 * 203. 移除链表元素
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * https://leetcode-cn.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;

        ListNode* to_del;
        ListNode* cur = head;
        while(cur->next) {
            if(cur->next->val == val) {
                to_del = cur->next;
                cur->next = to_del->next;
                delete to_del;
            } else {
                cur = cur->next;
            }
        }

        return head->val == val ? head->next : head;
    }
};
