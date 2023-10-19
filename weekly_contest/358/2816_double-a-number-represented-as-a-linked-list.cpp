/**
 * 2816. 翻倍以链表形式表示的数字
 * https://leetcode.cn/problems/double-a-number-represented-as-a-linked-list/description/
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
private:
    bool solve(ListNode *head) {
        if (!head)
            return false;

        bool carry = solve(head->next);
        head->val = carry + 2 * head->val;

        if (head->val >= 10) {
            head->val -= 10;

            return true;
        }

        return false;
    }

public:
    // 递归
    ListNode* doubleIt(ListNode* head) {
        bool carry = solve(head);
        if (carry)
            return new ListNode(1, head);

        return head;
    }
};
