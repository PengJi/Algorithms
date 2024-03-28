/**
 * 106. 从中序与后序遍历序列构造二叉树
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    unordered_map<int, int> pos;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        for (int i = 0; i < len; i++) {
            pos[inorder[i]] = i;
        }

        return dfs(inorder, postorder, 0, len - 1, 0, len - 1);
    }

    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
        if (pl > pr) return NULL;

        int k = pos[postorder[pr]] - il;

        TreeNode* root = new TreeNode(postorder[pr]);
        root->left = dfs(inorder, postorder, il, il + k - 1, pl, pl + k - 1);
        root->right = dfs(inorder, postorder, il + k + 1, ir, pl + k, pr - 1);

        return root;
    }
};

class Solution {
public:
    unordered_map<int, int> pos;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }

        return dfs(inorder, postorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
        if (pl > pr) return nullptr;

        int k = pos[postorder[pr]] - il;

        TreeNode* node = new TreeNode(postorder[pr]);
        node->left = dfs(inorder, postorder, il, il + k + 1, pl, pl + k - 1);
        node->right = dfs(inorder, postorder, il + k + 1, ir, pl + k, pr - 1);

        return node;
    }
};
