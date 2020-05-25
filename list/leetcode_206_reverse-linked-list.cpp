/**
 * 206. 反转链表
 * https://leetcode-cn.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL;
        ListNode* next;
        
        while (head) {
            next = head -> next;
            head -> next = cur;
            cur = head;
            head = next;
        }
        return cur;
    }
};