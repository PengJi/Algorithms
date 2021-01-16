/**
 * 1721. 交换链表中的节点
 * https://leetcode-cn.com/problems/swapping-nodes-in-a-linked-list/
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head, *slow = head;
        ListNode *left, *right;
        while(k > 1) {
            fast = fast->next;
            k--;
        }
        left = fast;

        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        right = slow;
        swap(left->val, right->val);

        return head;
    }
};
