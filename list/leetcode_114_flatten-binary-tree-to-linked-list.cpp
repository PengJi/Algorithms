/**
 * 114. 二叉树展开为链表
 * 给定一个二叉树，原地将它展开为一个单链表。
 * 
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode* root) {
        TreeNode* tmp;
        while(root) {
            // 有左右子节点
            if(root->left && root->right) {
                tmp = root->left;
                while(tmp->right) tmp = tmp->right;
                tmp->right = root->right;  // 将右子节点移动到左子树上
            }

            // 有左子节点，将左子节点移动到右子节点上
            if(root->left) root->right = root->left;

            root->left = NULL;
            root = root->right;
        }
    }
};
