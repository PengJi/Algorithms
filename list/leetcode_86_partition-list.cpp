/**
 * 86. 分隔链表
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * https://leetcode-cn.com/problems/partition-list/
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
    // 双指针 + 双链表
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;

        ListNode *less_head = new ListNode(0);
        ListNode *greater_head = new ListNode(0);
        ListNode *p1 = less_head, *p2 = greater_head;

        while(head) {
            if(head->val < x) {
                p1->next = head;
                p1 = p1->next;
                head = head->next;
            } else {
                p2->next = head;
                p2 = p2->next;
                head = head->next;
            }
        }

        p2->next = NULL;
        p1->next = greater_head->next;
        ListNode *res = less_head->next;
        delete less_head;
        delete greater_head;
        return res;
    }
};
