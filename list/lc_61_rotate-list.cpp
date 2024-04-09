/**
 * 61. 旋转链表
 * https://leetcode-cn.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left = head;   // 区间左指针
        ListNode* right = head;  // 区间右指针

        // 链表长度
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }

        k = k % len;  // 统计步长
        while (k--) {
            right = right->next;
        }
        while (right->next) {
            left = left->next;
            right = right->next;
        }

        // 修改链表
        right->next = dummy->next;
        dummy->next = left->next;
        left->next = nullptr;

        return dummy->next;
    }
};
