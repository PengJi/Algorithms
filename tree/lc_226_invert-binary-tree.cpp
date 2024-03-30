/**
 * 226. 翻转二叉树
 * https://leetcode-cn.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

    // 递归
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;

        return root;
    }

    // 迭代
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* cur = queue.front();
            TreeNode* tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;

            queue.pop();
            if (cur->left != nullptr) queue.push(cur->left);
            if (cur->right != nullptr) queue.push(cur->right);
        }

        return root;
    }
};
