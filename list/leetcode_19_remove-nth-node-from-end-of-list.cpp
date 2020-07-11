/**
 * 19. 删除链表的倒数第N个节点
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
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
    // 快慢指针
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return NULL;

        // 对于链表问题，返回结果为头结点时，通常需要先初始化一个预先指针 pre，
        // 该指针的下一个节点指向真正的头结点head。使用预先指针的目的在于链表初始化时无可用节点值，
        // 而且链表构造过程需要指针移动，进而会导致头指针丢失，无法返回结果。
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *left = dummy;
        ListNode *right = dummy;

        while(n--) {
            right = right->next;
        }

        while(right->next) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;

        ListNode *node = dummy->next;
        delete dummy;
        return node;
    }
};
