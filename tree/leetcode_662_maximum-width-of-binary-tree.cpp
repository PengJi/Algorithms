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

        int res = 0;
        queue<pair<TreeNode*, unsigned long>> que;  // 记录节点与位置
        que.push({root, 1});
        TreeNode* node;
        int len;
        unsigned long pos;

        while(!que.empty()) {
            len = que.size();
            res = max(res, int(que.back().second - que.front().second + 1));

            for(int i = 0; i < len; i++) {
                node = que.front().first;
                pos = que.front().second;
                que.pop();

                if(node->left) que.push({node->left, 2 * pos});
                if(node->right) que.push({node->right, 2 * pos +1});
            }
        }

        return res;
    }
};
