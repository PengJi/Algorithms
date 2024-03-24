/**
 * 144. 二叉树的前序遍历
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
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
    // 使用递归
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }

    void preorder(TreeNode* root, vector<int>& node) {
        if (!root) return;
        node.push_back(root->val);
        preorder(root->left, node);
        preorder(root->right, node);
    }

    // 使用迭代
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) return {};

        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* cur = root;

        // 当遍历到最后一个节点的时候，左右子树都为空，并且栈也为空
        // 当不同时满足这两点，都需要进入循环
        while (cur != NULL || !stk.empty()) {
            // 一直往左走
            while (cur != NULL) {
                res.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }

            // 一直到左子树为空，开始考虑右子树
            // 如果栈已空，就不再需要考虑
            if (!stk.empty()) {
                cur = stk.top();
                stk.pop();
                cur = cur->right;
            }
        }

        return res;
    }

    // 使用迭代
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return vector<int>();
        }

        vector<int> res;
        stack<TreeNode*> treeStack;
        treeStack.push(root);  //将根节点入栈

        while (!treeStack.empty()) {
            TreeNode* tmp = treeStack.top();
            res.push_back(tmp->val);
            treeStack.pop();

            // 先将右节点入栈
            if (tmp->right != NULL) {
                treeStack.push(tmp->right);
            }
            // 将左节点入栈
            if (tmp->left != NULL) {
                treeStack.push(tmp->left);
            }
        }

        return res;
    }
};
