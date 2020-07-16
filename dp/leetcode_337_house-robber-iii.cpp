/**
 * 337. 打家劫舍 III
 * https://leetcode-cn.com/problems/house-robber-iii/
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
    // 动态规划
    // https://leetcode-cn.com/problems/house-robber-iii/solution/shu-xing-dp-ru-men-wen-ti-by-liweiwei1419/
    // 时间复杂度：O()
    // 空间复杂度：O()
    int rob(TreeNode* root) {
        vector<int> res;
        res = dfs(root);
        return max(res[0], res[1]);
    }

    vector<int> dfs(TreeNode* node) {
        vector<int> dp{0, 0};
        if(node == NULL) return dp;

        // 分类讨论的标准是：当前结点偷或者不偷
        // 由于需要后序遍历，所以先计算左右子结点，然后计算当前结点的状态值
        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);

        // dp[0]：以当前 node 为根结点的子树能够偷取的最大价值，规定 node 结点不偷
        // dp[1]：以当前 node 为根结点的子树能够偷取的最大价值，规定 node 结点偷
        dp[0] = max(left[0], left[1]) + max(right[0], right[1]);
        dp[1] = node->val + left[0] + right[0];

        return dp;
    }
};
