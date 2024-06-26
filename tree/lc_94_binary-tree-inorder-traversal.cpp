/**
 * 94. 二叉树的中序遍历
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 递归
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode* root, vector<int>& vec) {
        if (root == NULL) return;
        traverse(root->left, vec);
        vec.push_back(root->val);
        traverse(root->right, vec);
    }

    // 迭代
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;  // 利用栈
        TreeNode* cur = root;

        while (!stk.empty() || cur != NULL) {
            while (cur != NULL) {
                stk.push(cur);
                cur = cur->left;  // 注意这里！！！
            }
            cur = stk.top();
            res.push_back(cur->val);
            stk.pop();

            cur = cur->right;
        }

        return res;
    }
};
