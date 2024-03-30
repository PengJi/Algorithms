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
        if (!root) return;

        vector<int> res;
        dfs(root, res);

        return res;
    }

    void dfs(TreeNode* node, vector<int>& res) {
        if (!node) return;
        dfs(node->left, res);
        dfs(node->right, res);

        res.push_back(node->val);
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* last = root;

        while(!stk.empty() || cur != nullptr) {
            while(cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top();
            if(cur->right == nullptr || cur->right == last) {  // 左右节点都遍历完
                res.emplace_back(cur->val);
                stk.pop();
                last = cur;
                cur = nullptr;
            } else {
                cur = cur->right;
            }
        }

        return res;
    }
};
