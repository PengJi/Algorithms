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
typedef long long LL;

class Solution {
public:
    // BFS + 堆
    LL kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<LL, vector<LL>, greater<LL>> heap;
        vector<TreeNode*> t1;

        t1.push_back(root);

        while (!t1.empty()) {
            vector<TreeNode*> t2;
            LL sum = 0;
            for (TreeNode *u : t1) {
                sum += u->val;

                if (u->left) t2.push_back(u->left);
                if (u->right) t2.push_back(u->right);
            }

            heap.push(sum);
            if (heap.size() > k)
                heap.pop();

            t1 = t2;
        }

        if (heap.size() < k)
            return -1;

        return heap.top();
    }
};
