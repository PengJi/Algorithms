/**
 * 141. 环形链表
 * https://leetcode-cn.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }

        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* s = head, *f = head->next;
        while(f) {
            s = s->next, f = f->next;
            if(!f) return false;
            f = f->next;
            if(s == f) return true;
        }

        return false;
    }
};

