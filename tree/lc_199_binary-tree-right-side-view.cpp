/**
 * 199. 二叉树的右视图
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int len = q.size();
            TreeNode* node;

            for (int i = 0; i < len; i++) {
                node = q.front();
                q.pop();

                if (i == len - 1) res.emplace_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return res;
    }
};