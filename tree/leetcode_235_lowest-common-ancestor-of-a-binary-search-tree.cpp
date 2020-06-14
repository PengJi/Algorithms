/**
 * 235. 二叉搜索树的最近公共祖先
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p->val;
        int qVal = q->val;

        if(pVal < root->val && qVal < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if(pVal > root->val && qVal > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
    
    // 递归
    // https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solution/lca-by-ai-mao-de-xiao-gen-ban/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //递归边界返回空或者返回存在的那个结点
        if(root==NULL||root==p||root==q) return root;
        //左边找一找
        TreeNode* L = lowestCommonAncestor(root->left,p,q);
        //右边找一找
        TreeNode* R = lowestCommonAncestor(root->right,p,q);
        //返回NULL或者有的那一侧
        if(L == NULL) return R;
        if(R == NULL) return L;
        //当前祖先左边有p，右边有q
        return root; 
    }
};
