/**
 * 98. 验证二叉搜索树
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * https://leetcode-cn.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }

    bool isValidBST(TreeNode *root, TreeNode* lower, TreeNode* upper){
        if(root == nullptr) return true;

        if(lower && root->val <= lower->val || upper && root->val >= upper->val) return false;

        return isValidBST(root->left, lower, root) && isValidBST(root->right, root, upper);
    }
};
