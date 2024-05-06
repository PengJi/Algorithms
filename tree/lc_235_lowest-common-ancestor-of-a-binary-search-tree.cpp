/**
 * 235. 二叉搜索树的最近公共祖先
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
    // 根结点必定是候选公共祖先，接着如果 p 和 q 同时出现在左子树，则我们往左儿子移动；如果 p 和 q 同时出现在右子树，则我们往右儿子移动；
    // 若不满足上述两个条件，则停止寻找，当前结点就是最近公共祖先。
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else {
                break;
            }
        }

        return root;
    }
};
