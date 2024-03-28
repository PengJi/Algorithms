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

    // 对于 s 的每一个结点，都尝试与 t 进行匹配，此操作可递归执行
    bool dfs(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        return isSame(s, t) || dfs(s->left, t) || dfs(s->right, t);
    }

    // 匹配时，仍然需要递归匹配当前 s 中的子树和 t 的每一个结点
    bool isSame(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s && t || s && !t || s->val != t->val) return false;

        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot) || isSame(root, subRoot);
    }

    bool isSame(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 && t2 || t1 && !t2 || t1->val != t2->val) return false;

        return isSame(t1->left, t2->left) && isSame(t1->right, t2->right);
    }
};
