/**
 * 剑指 Offer 22. 链表中倒数第k个节点
 * https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
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
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* front = head;
        ListNode* rear = head;
        for(int i = 0; i < k; i++) {  // 相差 k
            front = front->next;
        }

        while(front != NULL) {
            front = front->next;
            rear = rear->next;
        }

        return rear;
    }
};
