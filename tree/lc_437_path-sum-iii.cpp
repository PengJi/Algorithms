/**
 * 437. 路径总和 III
 * https://leetcode.cn/problems/path-sum-iii/
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
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> store;
        return helper(root, sum, store, 0);
    }

    int helper(TreeNode* root, int sum, unordered_map<int, int>& store, int pre) {
        if(root == NULL) return 0;

        root->val += pre;
        int res = (root->val == sum) + (store.count(root->val - sum) ? store[root->val - sum] : 0);
        store[root->val]++;
        
        res += helper(root->left, sum, store, root->val) + helper(root->right, sum, store, root->val);
        store[root->val]--;

        return res;
    }
};
