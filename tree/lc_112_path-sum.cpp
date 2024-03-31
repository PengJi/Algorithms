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
        if (root == NULL) return false;

        cur += root->val if (root->left == NULL && root->right == NULL) {
            return cur == sum;
        }

        return helper(root->left, cur, sum) || helper(root->right, cur, sum);
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        if(!root->left && !root->right) {
            return targetSum - root->val == 0;
        }

        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};
