/**
 * 剑指 Offer 26. 树的子结构
 * https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
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
    // 递归
    // 时间复杂度：O(mn)
    // 空间复杂度：O(m)
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A!=NULL && B!=NULL) && (dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

    bool dfs(TreeNode* A, TreeNode* B) {
        if(B == NULL) return true;  // 如果 B 全部遍历，则是子结构
        if(A == NULL || A->val != B->val) return false;  // 如果 A 未全部遍历，则不是子结构
        return dfs(A->left, B->left) && dfs(A->right, B->right); 
    }
};
