/**
 * 94. 二叉树的中序遍历
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode* root, vector<int> &vec){
        if(root != NULL){
            traverse(root->left, vec);
            vec.push_back(root->val);  // 中序遍历
            traverse(root->right, vec);
        }
    }

    // 迭代
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};

        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* cur = root;

        while(cur != NULL || !stk.empty()) {
            while(cur != NULL) {
                stk.push(cur);
                cur = cur->left;
            }

            if(!stk.empty()) {
                cur = stk.top();
                res.push_back(cur->val);
                stk.pop();
                cur = cur->right;
            }
        }

        return res;
    }

    // 迭代
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;  // 利用栈
        TreeNode* cur = root;

        while(!stk.empty() || cur != NULL) {
            while(cur != NULL){
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            res.push_back(cur->val);
            stk.pop();

            cur = cur->right;
        }

        return res;
    }
};
