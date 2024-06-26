/**
 * 257. 二叉树的所有路径
 * https://leetcode-cn.com/problems/binary-tree-paths/
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
    // dfs，前序遍历
    // https://leetcode-cn.com/problems/binary-tree-paths/solution/257-er-cha-shu-de-suo-you-lu-jing-tu-wen-jie-xi-by/
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }

    void dfs(TreeNode* root, string path, vector<string>& paths) {
        if (!root) return;

        path += to_string(root->val);

        if (!root->left && !root->right) {
            paths.push_back(path);
            return;
        }

        dfs(root->left, path + "->", paths);
        dfs(root->right, path + "->", paths);
    }
};
