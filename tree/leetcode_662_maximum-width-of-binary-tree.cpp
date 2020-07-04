/**
 * 662. 二叉树最大宽度
 * https://leetcode-cn.com/problems/maximum-width-of-binary-tree/
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
    // 层序遍历，记录每个节点的位置
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int res = 1;
        queue<pair<TreeNode*, unsigned long>> q;
        q.push({root, 1});
        while(!q.empty()) {
            int len = q.size();
            res = max(res, int(q.back().second - q.front().second + 1));
            for(int i = 0; i < len; i++) {
                TreeNode* node = q.front().first;
                unsigned long pos = q.front().second;
                if(node->left) q.push({node->left, 2*pos});
                if(node->right) q.push({node->right, 2*pos+1});
                q.pop();
            }
        }

        return res;
    }
};
