/**
 * 24. 两两交换链表中的节点
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/
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
    // 递归
    // 时间复杂度：O(n)
    // 空闲复杂度：O(n)
    ListNode* swapPairs(ListNode* head) {
        // 如果有一个节点或者没有节点
        if((head == NULL) || (head->next == NULL)){
            return head;
        }

        // 待反转的节点
        ListNode* start = head;
        ListNode* end = head->next;

        // 反转
        start->next = swapPairs(end->next);
        end->next = start;

        return end;
    }

    // 迭代
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;

        ListNode *start, *end;
        while(cur != NULL && cur->next != NULL) {
            // 待反转的节点
            start = cur;
            end = cur->next;

            // 反转
            pre->next = end;
            start->next = end->next;
            end->next = start;

            // 初始化下一个反转的节点
            pre = start;
            cur = start->next;
        }

        return dummy->next; 
    }

};
