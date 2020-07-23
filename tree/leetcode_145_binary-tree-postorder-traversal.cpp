/**
 * 145. 二叉树的后序遍历
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};

        vector<int> res;
        traverse(root, res);

        return res;
    }

    void traverse(TreeNode* node, vector<int>& res) {
        if(node != NULL) {
            traverse(node->left, res);
            traverse(node->right, res);

            res.push_back(node->val);
        }
    }

    // 遍历
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};

        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        TreeNode* last_visit = root;

        while(!stk.empty() || node != NULL) {
            while(node != NULL) {
                stk.push(node);
                node = node->left;
            }

            node = stk.top();

            if(node->right == NULL || node->right == last_visit) {
                res.push_back(node->val);
                stk.pop();
                last_visit = node;
                node = NULL;
            } else {
                node = node->right;
            }
        }

        return res;
    }
};
