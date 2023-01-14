/**
 * 572. 另一个树的子树
 * 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
 * s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
 * 
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

    bool dfs(TreeNode* o, TreeNode* t) {
        if(!o) return false;
        return check(o, t) || dfs(o->left, t) || dfs(o->right, t);
    }

    bool check(TreeNode* o, TreeNode* t) {
        if(!o && !t) return true;
        if((o && !t) || (!o && t) || (o->val != t->val)) return false;
        
        return check(o->left, t->left) && check(o->right, t->right);
    }
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s, t);
    }

    // 对于 s 的每一个结点，都尝试与 t 进行匹配，此操作可递归执行
    bool dfs(TreeNode *s, TreeNode *t) {
        if (!s) return false;
        return isSame(s, t) || dfs(s -> left, t) || dfs(s -> right, t);
    }

    // 匹配时，仍然需要递归匹配当前 s 中的子树和 t 的每一个结点
    bool isSame(TreeNode *s, TreeNode *t) {
        if (!s && !t) return true;
        if (!s && t || s && !t || s -> val != t -> val)
            return false;

        return isSame(s -> left, t -> left) && isSame(s -> right, t -> right);
    }
};
