/**
 * 563. 二叉树的坡度
 * 给定一个二叉树，计算整个树的坡度。
 * 一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。
 * 整个树的坡度就是其所有节点的坡度之和。
 * 
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
        if(root == nullptr) return 0;

        int left = traverse(root->left);
        int right = traverse(root->right);

        res += abs(left - right);
        return left + right + root->val;
    }
};

class Solution {
public:
    int res = 0;

    int findTilt(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if(!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        res += abs(left - right);
        return left + right + root->val;
    }
};
