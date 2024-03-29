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
    // O(n^2)/O(n）
    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        if (!root)
            return res;

        res += dfs(root, targetSum);  // 深度优先计算以当前节点为根节点的路径数
        res += pathSum(root->left, targetSum);  // 遍历左子树
        res += pathSum(root->right, targetSum);  // 遍历右子树

        return res;
    }

    int dfs(TreeNode* root, long targetSum) {
        if (!root) return 0;
        int res = 0;

        if (root->val == targetSum) res++;

        res += dfs(root->left, targetSum - root->val);
        res += dfs(root->right, targetSum - root->val);

        return res;
    }
};

class Solution {
public:
    unordered_map<long, long> mp;
    int res = 0;

    // 前缀和
    int pathSum(TreeNode* root, long sum) {
        mp[0] ++ ;
        dfs(root, sum, 0);
        return res;
    }

    void dfs(TreeNode* root, long sum, long cur) {
        if (!root) return;

        cur += root->val;
        res += mp[cur - sum];

        mp[cur] ++ ;

        dfs(root->left, sum, cur);
        dfs(root->right, sum, cur);

        mp[cur] -- ;
    }
};