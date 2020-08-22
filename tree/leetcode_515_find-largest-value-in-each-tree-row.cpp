/**
 * 515. 在每个树行中找最大值
 * 您需要在二叉树的每一行中找到最大的值。
 * 
 * https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/
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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};

        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int max = INT_MIN;
            int len = que.size();

            for (int i = 0; i < len; i++) {
                max = (que.front()->val > max) ? que.front()->val : max;

                if (que.front()->left)
                    que.push(que.front()->left);

                if (que.front()->right)
                    que.push(que.front()->right);

                que.pop();
            }

            res.push_back(max);
        }

        return res;
    }
};
