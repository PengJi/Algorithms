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
    int res = 0;

    // https://www.acwing.com/solution/content/223/
    // O(n)
    // O(1)
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    // 从根节点递归遍历整棵树，遍历时维护从根节点到该节点的路径表示的数，当遍历到叶节点时，将路径表示的数累加到答案中。
    void dfs(TreeNode* root, int sum) {
        if (!root) return;
        sum = (sum * 10 + root->val);
        if (root->left) dfs(root->left, sum);
        if (root->right) dfs(root->right, sum);
        if (!root->left && !root->right) res += sum;
    }
};
