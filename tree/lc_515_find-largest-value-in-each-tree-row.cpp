/**
 * 515. 在每个树行中找最大值
 * https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/
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
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL) return {};

        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int max = INT_MIN;
            int len = que.size();

            for (int i = 0; i < len; i++) {
                max = (que.front()->val > max) ? que.front()->val : max;

                if (que.front()->left) que.push(que.front()->left);
                if (que.front()->right) que.push(que.front()->right);

                que.pop();
            }

            res.push_back(max);
        }

        return res;
    }
};

class Solution {
public:
    // 这个算法比较巧妙，一般需要借助一个哈希表记录每一行的最大值，但这里直接使用结果数组当作哈希表。
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;  // 充当哈希表的作用，存储每一行的最大值。
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode* node, int dep, vector<int>& vec) {
        if (node == NULL) return;  // 递归返回条件

        // 比较巧妙，如果结果数组的大小与当前行相等，则说明当前行没有元素，将元素加入当前行。
        if (vec.size() == dep) vec.push_back(node->val);
        // 比较当前元素的当前行的最大值
        if (node->val > vec[dep]) vec[dep] = node->val;

        // 遍历左子树和右子树
        dfs(node->left, dep + 1, vec);
        dfs(node->right, dep + 1, vec);
    }
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root) q.push(root);

        while(!q.empty()) {
            int len = q.size();
            int max = INT_MIN;

            while(len--) {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->val > max) max = cur->val; 

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }

            res.push_back(max);
        }

        return res;
    }
};
