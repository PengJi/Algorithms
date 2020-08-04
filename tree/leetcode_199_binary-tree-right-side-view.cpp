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
