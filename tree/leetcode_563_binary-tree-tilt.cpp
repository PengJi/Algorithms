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
    int findTilt(TreeNode* root) {
        int res = 0;
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode* root, int &res){
        if(root == nullptr) return;
        int left = traverse(root->left, res);
        int right = traverse(root->right, res);
        res += abs(left - right);
    }
};