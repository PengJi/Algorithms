/**
 * 543. 二叉树的直径
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/
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
    int ans;

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        dfs(root);
        return ans - 1;
    }

    int dfs(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int L = dfs(root->left);
        int R = dfs(root->right);
        ans = max(ans, L+R+1);
        return max(L, R) + 1;
    }
};
