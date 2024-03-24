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
    // https://www.acwing.com/solution/content/89/
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode *leftp = root, *rightp = root;
        int l = 0, r = 0;
        while (leftp) {
            l++;
            leftp = leftp->left;
        }
        while (rightp) {
            r++;
            rightp = rightp->right;
        }
        if (l == r) return (1 << l) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
