/**
 * 107. 二叉树的层次遍历 II
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 
 * （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
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
    // DFS
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> ans(d, vector<int> {});
        levelOrder(ans, root, d-1);
        return ans;
    }

    void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
        if (!node) return;
        ans[level].push_back(node->val);
        
        levelOrder(ans, node->left, level-1);
        levelOrder(ans, node->right, level-1);
    }

    int depth(TreeNode *root) {
        if (!root) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
};
