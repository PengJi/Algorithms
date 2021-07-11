/**
 * 95. 不同的二叉搜索树 II
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
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
    // 深度优先
    // https://www.acwing.com/solution/content/177/
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        return dfs(1, n);
    }

    // 左右边界
    vector<TreeNode*> dfs(int l, int r) {
        vector<TreeNode*> res;
        if(l > r) {
            res.push_back(NULL);
            return res;
        }
        
        // i 为根节点
        for(int i = l; i <= r; i++) {
            vector<TreeNode*> left = dfs(l, i-1);
            vector<TreeNode*> right = dfs(i+1, r);
            // 对于每个根节点，添加左右子树
            for(auto lc : left) 
                for(auto rc : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lc;
                    root->right = rc;
                    res.push_back(root);
                }
        }

        return res;
    }
};
