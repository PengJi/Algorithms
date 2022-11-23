/**
 * 2471. 逐层排序二叉树所需的最少操作数目
 * https://leetcode.cn/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/
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
    // 计算环图个数
    int cal(const vector<int> &c) {
        const int n = c.size();

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = i;

        sort(arr.begin(), arr.end(), [&](int x, int y) {
            return c[x] < c[y];
        });

        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = arr[i];

            while (j != i) {
                res++;
                int t = arr[j];
                arr[j] = j;
                j = t;
            }

            arr[i] = j;
        }

        return res;
    }

    // 环图
    // 对树按照从左到右的顺序进行层级遍历，对于每一层节点的值，求当前层的操作数目
    // 通过排序求出每个位置应该放置的数组下标，最小交换次数就是排序后的下标数组中，总个数减去 环 的个数。
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;

        while(!q.empty()) {
            int len = q.size();
            vector<int> vec;

            for(int i = 0; i < len; i++) {
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            res += cal(vec);
        }

        return res;
    }
};
