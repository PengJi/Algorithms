/**
 * 25. K 个一组翻转链表
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
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
    // 遍历
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* end = dummy;

        while(end->next != NULL) {
            for(int i = 0; i < k && end != NULL; i++){
                end = end->next;
            } 
            if(end == NULL) break;
            ListNode* start = pre->next;
            ListNode* next = end->next;
            end->next = NULL;
            pre->next = reverse(start);
            start->next = next;
            pre = start;

            end = pre;
        }

        return dummy->next;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;

        while(cur != NULL){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};
