/**
 * 563. 二叉树的坡度
 * https://leetcode-cn.com/problems/binary-tree-tilt/
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
    int res = 0;

    // 递归
    // O(n)/O(n)
    int findTilt(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        res += abs(left - right);

        return left + right + root->val;
    }
};
