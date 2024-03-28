/**
 * 654. 最大二叉树
 * https://leetcode-cn.com/problems/maximum-binary-tree/
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
    // 单调栈
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;

        for (int i = 0; i < nums.size(); ++i) {
            TreeNode* cur = new TreeNode(nums[i]);

            while (!stk.empty() && stk.back()->val < nums[i]) {
                cur->left = stk.back();
                stk.pop_back();
            }

            if (!stk.empty()) stk.back()->right = cur;

            stk.push_back(cur);
        }

        return stk.front();
    }
};

class Solution {
public:
    // 深搜
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode* dfs(vector<int> nums, int left, int right) {
        if (left > right) return nullptr;

        int m = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[m] < nums[i]) m = i;
        }

        TreeNode* node = new TreeNode(nums[m]);
        node->left = dfs(nums, left, m - 1);
        node->right = dfs(nums, m + 1, right);

        return node;
    }
};
