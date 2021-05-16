/**
 * 230. 二叉搜索树中第K小的元素
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
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
    int cnt, ans;

    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        if(root == NULL) return;
        dfs(root->left);
        if(--cnt == 0) {
            ans = root->val;
            return;
        }
        dfs(root->right);
    }
};
