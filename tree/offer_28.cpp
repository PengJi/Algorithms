/**
 * 剑指 Offer 28. 对称的二叉树
 * https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
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
    bool isSymmetric(TreeNode* root) {
        return root == NULL ? true : dfs(root->left, root->right);
    }

    bool dfs(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL || left->val != right->val) return false;
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};
