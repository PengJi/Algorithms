/**
 * 110. 平衡二叉树
 * https://leetcode-cn.com/problems/balanced-binary-tree/
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
    // 从上到下遍历
    // O(n^2)/O(n)
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return abs(dfs(root->left) - dfs(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }
};

class Solution {
public:
    // 从下到上遍历
    // O(n)/O(n)
    bool isBalanced(TreeNode* root) {
        return dfs(root) >= 0;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == -1 || right == -1 || abs(left - right) > 1) return -1;

        return max(left, right) + 1;
    }
};