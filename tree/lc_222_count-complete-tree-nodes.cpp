/**
 * 222. 完全二叉树的节点个数
 * https://leetcode-cn.com/problems/count-complete-tree-nodes/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode* ln = root;
        TreeNode* rn = root;
        int l = 0, r = 0;

        while (ln) {
            l++;
            ln = ln->left;
        }
        while (rn) {
            r++;
            rn = rn->right;
        }

        if (l == r) return (1 << l) - 1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int left = countNodes(root->left);
        int right = countNodes(root->right);

        return left + right + 1;
    }
};
