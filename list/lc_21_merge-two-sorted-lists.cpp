/**
 * 21. 合并两个有序链表
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/
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
    // 迭代
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }

            pre = pre->next;
        }

        pre->next = l1 != NULL ? l1 : l2;

        ListNode* node = dummy->next;
        delete dummy;
        return node;
    }
};

class Solution {
public:
    // 递归
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class Solution {
public:
    // 双指针遍历
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);  // 合并链表头结点的前一个节点，方便返回头结点
        ListNode* tail = dummy;             // 合并链表尾结点

        // 比较大小并串联链表
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        // 还有未合并的链表
        tail->next = l1 ? l1 : l2;

        // 合并链表的头结点
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
