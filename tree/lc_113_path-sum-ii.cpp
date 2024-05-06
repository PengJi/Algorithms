/**
 * 113. 路径总和 II
 * https://leetcode-cn.com/problems/path-sum-ii/
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
    vector<vector<int>> res;
    vector<int> path;

    // dfs
    // https://leetcode-cn.com/problems/path-sum-ii/solution/lu-jing-zong-he-ii-by-leetcode-solution/
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return res;
    }

    void dfs(TreeNode* root, int sum) {
        if (!root) return;

        path.push_back(root->val);
        sum -= root->val;
        if (!root->left && !root->right && sum == 0) {
            res.push_back(path);
        }

        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back();  // 注意：需要记录路径，所以需要 pop;
    }
};
