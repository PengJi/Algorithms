/**
 * 199. 二叉树的右视图
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
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
        if (root == nullptr) return {};

        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);

        int len;
        TreeNode* q;
        while (!que.empty()) {
            len = que.size();

            for (int i = 0; i < len; i++) {
                q = que.front();
                que.pop();

                if (i == len - 1) {
                    ans.push_back(q->val);
                }

                if (q->left) {
                    que.push(q->left);
                }
                if (q->right) {
                    que.push(q->right);
                }
            }
        }

        return ans;
    }
};
