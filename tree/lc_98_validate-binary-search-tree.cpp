/**
 * 98. 验证二叉搜索树
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root) {
        return dfs(root, NULL, NULL);
    }

    // 递归
    bool dfs(TreeNode* root, TreeNode* lower, TreeNode* upper) {
        if (root == NULL) return true;
        if (lower && root->val <= lower->val || upper && root->val >= upper->val) return false;
        return dfs(root->left, lower, root) && dfs(root->right, root, upper);
    }
};

class Solution {
public:
    // 中序遍历
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        long long inorder = LONG_MIN;

        while(!stk.empty() || cur != NULL) {
            while(cur) {
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top();
            stk.pop();

            if(cur->val <= inorder) {
                return false;
            }

            inorder = cur->val;
            cur = cur-> right;
        }

        return true;
    }
};
