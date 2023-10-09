/**
 * 2807. 在链表中插入最大公约数
 * https://leetcode.cn/problems/insert-greatest-common-divisors-in-linked-list/description/
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *p1 = head, *p2 = head->next;

        while (p2) {
            int g = gcd(p1->val, p2->val);
            p1->next = new ListNode(g, p2);
            p1 = p2;
            p2 = p2->next;
        }

        return head;
    }
};
