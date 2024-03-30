/**
 * 144. 二叉树的前序遍历
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
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
    // 使用递归
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }

    void preorder(TreeNode* root, vector<int>& node) {
        if (!root) return;
        node.push_back(root->val);
        preorder(root->left, node);
        preorder(root->right, node);
    }
};

class Solution {
public:
    // 使用迭代
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;

        while (!stk.empty() || cur != nullptr) {
            while (cur != nullptr) {
                res.emplace_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top();
            stk.pop();
            cur = cur->right;
        }

        return res;
    }
};
