/**
 * 111. 二叉树的最小深度
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftHeight = minDepth(root->left);
        int rightHeight = minDepth(root->right);
        if(!leftHeight || !rightHeight) return leftHeight+rightHeight+1;
        
        return min(leftHeight, rightHeight) + 1;
    }
};
