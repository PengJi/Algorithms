/**
 * 572. 另一个树的子树
 * https://leetcode-cn.com/problems/subtree-of-another-tree/
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
    // 递归
    // 时间复杂度：O(m * n)
    // 空间复杂度：O(max(m, n))
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s, t);
    }

    bool dfs(TreeNode* o, TreeNode* t){
        if(!o) return false;
        return check(o, t) || dfs(o->left, t) || dfs(o->right, t);
    }

    bool check(TreeNode* o, TreeNode* t){
        if(!o && !t) return true;
        if((o && !t) || (!o && t) || (o->val != t->val)) return false;
        return check(o->left, t->left) && check(o->right, t->right);
    }
};
