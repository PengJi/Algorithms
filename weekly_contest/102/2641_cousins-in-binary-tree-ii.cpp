/**
 * 2641. 二叉树的堂兄弟节点 II
 * https://leetcode.cn/problems/cousins-in-binary-tree-ii/
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
    // 层级遍历
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<TreeNode*> q1, q2;
        q1.push_back(root);
        root->val = 0;

        while (!q1.empty()) {
            int tot = 0;
            for (auto u : q1) {
                if (u->left) {
                    tot += u->left->val;
                    q2.push_back(u->left);
                }

                if (u->right) {
                    tot += u->right->val;
                    q2.push_back(u->right);
                }
            }

            for (auto u : q1) {
                int r = tot;

                if (u->left) r -= u->left->val;
                if (u->right) r -= u->right->val;

                if (u->left) u->left->val = r;
                if (u->right) u->right->val = r;
            }

            q1 = q2;
            q2.clear();
        }

        return root;
    }
};
