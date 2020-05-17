/**
 * 102. 二叉树的层序遍历
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
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
    // 层序遍历
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) return ret;

        queue <TreeNode*> q;
        q.push(root);
        int currentLevelSize;
        while (!q.empty()) {
            currentLevelSize = q.size();
            vector<int> vec;
            for (int i = 1; i <= currentLevelSize; ++i) {  // 遍历每一层
                TreeNode* node = q.front(); 
                q.pop();
                vec.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ret.push_back(vec);
        }
        
        return ret;
    }
};