/**
 * 6223. 移除子树后的二叉树高度
 * https://leetcode.cn/problems/height-of-binary-tree-after-subtree-removal-queries/
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
private:
    unordered_map<TreeNode*, int> h;
    unordered_map<int, int> ans;

    void get_h(TreeNode *root) {
        if (!root)
            return;

        get_h(root->left);
        get_h(root->right);

        h[root] = max(h[root->left], h[root->right]) + 1;
    }

    void get_ans(TreeNode *root, int level, int ma) {
        if (root->left) {
            ans[root->left->val] = max(ma, h[root->right] + level + 1);
            get_ans(root->left, level + 1, ans[root->left->val]);
        }

        if (root->right) {
            ans[root->right->val] = max(ma, h[root->left] + level + 1);
            get_ans(root->right, level + 1, ans[root->right->val]);
        }
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        h[nullptr] = -1;
        get_h(root);
        get_ans(root, 0, 0);

        for (int &q : queries)
            q = ans[q];

        return queries;
    }
};
