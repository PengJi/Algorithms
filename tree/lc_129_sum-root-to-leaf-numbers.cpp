/**
 * 129. 求根节点到叶节点数字之和
 * https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
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
    int ans = 0;

    // https://www.acwing.com/solution/content/223/
    // O(n)
    // O(1)
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* root, int sum) {
        if(!root) return;
        sum = (sum * 10 + root->val);
        if(root->left) dfs(root->left, sum);
        if(root->right) dfs(root->right, sum);
        if(!root->left && !root->right) ans += sum;
    }
};
