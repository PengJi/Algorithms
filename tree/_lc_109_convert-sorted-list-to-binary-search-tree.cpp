/**
 * 109. 有序链表转换二叉搜索树
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return 0;
        int l = 0;
        for (auto i = head; i; i = i->next) l++;
        l /= 2;

        ListNode* p = head;
        for (int i = 0; i < l; i++) p = p->next;
        TreeNode* root = new TreeNode(p->val);

        root->right = sortedListToBST(p->next);
        if (l) {
            p = head;
            for (int i = 0; i < l - 1; i++) p = p->next;
            p->next = 0;
            root->left = sortedListToBST(head);
        }
        return root;
    }
};
