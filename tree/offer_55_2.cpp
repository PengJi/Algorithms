/**
 * 剑指 Offer 55 - II. 平衡二叉树
 * https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return abs(dfs(root->left) - dfs(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int dfs(TreeNode* root) {
        if(root == NULL) return 0;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }
};
