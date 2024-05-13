/**
 * 86. 分隔链表
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
    // O(n)/O(1)
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return NULL;

        ListNode* less_head = new ListNode(0);     // 小于链表
        ListNode* greater_head = new ListNode(0);  // 大于等于链表
        // 小于指针，大于等于指针
        ListNode *p1 = less_head, *p2 = greater_head;

        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }

        p2->next = NULL;
        p1->next = greater_head->next;
        ListNode* res = less_head->next;
        delete less_head;
        delete greater_head;
        return res;
    }
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;

        ListNode* left_head = new ListNode(0);   // 小于 x 的列表
        ListNode* right_head = new ListNode(0);  // 大于等于 x 的列表
        ListNode* left = left_head;
        ListNode* right = right_head;

        while (head) {
            if (head->val < x) {
                left->next = head;  // 修改指针
                left = left->next;  // 修改当前节点
            } else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }

        right->next = nullptr;
        left->next = right_head->next;

        return left_head->next;
    }
};
