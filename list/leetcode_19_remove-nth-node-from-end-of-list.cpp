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

        ListNode* pre = new ListNode(0);
        pre->next = head;

        ListNode* first = pre;
        ListNode* second = pre;
        
        while(n != 0) {
            first = first->next;
            n--;
        }

        while(first->next != nullptr){
            first = first -> next;
            second = second -> next;
        }
        second->next = second->next->next;
        ListNode* node = pre->next;
        delete pre;
        return node;

    }
};

