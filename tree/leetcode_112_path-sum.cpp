/**
 * 112. 路径总和
 * https://leetcode-cn.com/problems/path-sum/
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
    // 递归，记录路径和
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    bool hasPathSum(TreeNode* root, int sum) {
        return helper(root, 0, sum);
    }

    bool helper(TreeNode* root, int cur, int sum) {
        if(root == NULL) return false;

        cur += root->val
        if(root->left == NULL && root->right == NULL) {
            return cur == sum;
        }

        return helper(root->left, cur, sum) || helper(root->right, cur, sum);
    }

    // 递归，减去路径和
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;

        // 判断是否为页结点
        if(root->left == NULL && root->right == NULL) {
            return sum-root->val == 0;
        }

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
