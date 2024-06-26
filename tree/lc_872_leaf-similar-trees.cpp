/**
 * 872. 叶子相似的树
 * https://leetcode-cn.com/problems/leaf-similar-trees/
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
    // 前序遍历，存储叶子节点
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);

        return leaves1 == leaves2;
    }

    void dfs(TreeNode* node, vector<int>& leaves) {
        if (node == NULL) return;

        if (node->left == NULL && node->right == NULL)
            leaves.push_back(node->val);

        dfs(node->left, leaves);
        dfs(node->right, leaves);
    }
};
