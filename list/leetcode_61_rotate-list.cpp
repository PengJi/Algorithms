/**
 * 61. 旋转链表
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 
 * https://leetcode-cn.com/problems/rotate-list/
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
    // 双指针
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* left = head;
        ListNode* right = head;

        // 获取链表长度
        int len = 1;
        while(head->next) {
            head = head->next;
            len++;
        }
        k %= len;

        // 移动步长
        while(k--) {
            right = right->next;
        }
        // 移动双指针
        while(right->next) {
            left = left->next;
            right = right->next;
        }

        // 修改链表
        right->next = dummy->next;
        dummy->next = left->next;
        left->next = NULL;

        return dummy->next;
    }
};
