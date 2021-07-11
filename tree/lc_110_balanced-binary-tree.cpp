/**
 * 110. 平衡二叉树
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
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
    // 递归
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    bool isBalanced(TreeNode* root) {
        // An empty tree satisfies the definition of a balanced tree
        if (root == nullptr) return true;

        // Check if subtrees have height within 1. If they do, check if the
        // subtrees are balanced
        return abs(height(root->left) - height(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }

    // Recursively obtain the height of a tree. An empty tree has -1 height
    int height(TreeNode* root) { 
        // An empty tree has height -1
        if (root == nullptr) return -1;

        return max(height(root->left), height(root->right)) + 1;
    }
};
