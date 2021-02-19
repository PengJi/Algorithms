/**
 * 剑指 Offer 06. 从尾到头打印链表
 * https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
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
    // 利用栈
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> reversePrint(ListNode* head) {
        if(head == NULL) return {};
        stack<int> stk;
        while(head != NULL) {
            stk.push(head->val);
            head = head->next;
        }

        vector<int> ans;
        while(!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }

        return ans;
    }
};
