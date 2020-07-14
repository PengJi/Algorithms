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
    // 递归
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int res = 0;

    int findTilt(TreeNode* root) {
        traverse(root);
        return res;
    }

    int traverse(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int left = traverse(root->left);
        int right = traverse(root->right);
        
        res += abs(left - right);
        return left + right + root->val;
    }
};
