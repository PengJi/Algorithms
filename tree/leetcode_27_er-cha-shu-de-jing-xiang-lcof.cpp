/**
 * 面试题27. 二叉树的镜像
 * https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL) return NULL;

        TreeNode* tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);

        return root;
    }

    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) return NULL;

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        mirrorTree(root->left);
        mirrorTree(root->right);

        return root;
    }
};
