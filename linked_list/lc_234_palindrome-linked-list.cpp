/**
 * 234. 回文链表
 * https://leetcode.cn/problems/palindrome-linked-list/description/
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
    // 将链表的一半翻转
    // O(n)/O(1)
    bool isPalindrome(ListNode* head) {
        // 零个或单个节点
        if (!head || !head->next) return true;
        // 两个节点
        if (head->next != nullptr && head->next->next == nullptr)
            return head->val == head->next->val;

        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 反转链表，返回头节点
        ListNode* tail = reverse(slow->next);

        while (tail) {  // 只判断反转后的链表
            if (head->val != tail->val) return false;
            head = head->next;
            tail = tail->next;
        }

        return true;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* next;

        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};
