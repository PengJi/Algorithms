/**
 * 2476. 二叉搜索树最近节点查询
 * https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/description/
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
    vector<int> vec;

    void traverse(TreeNode* n) {
        if(!n) return;
        traverse(n->left);
        vec.push_back(n->val);
        cout << n-> val << " ";
        traverse(n->right);
    }

    // 中序遍历 + 二分查找
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        traverse(root);
        int len = vec.size();
        vector<vector<int>> res;

        for(auto x: queries) {
            vector<int> tmp = {-1, -1};
            int idx = bsearch(0, len-1, x);

            if(vec[idx] == x) {
                tmp[0] = x, tmp[1] = x;
            } else if(idx == 0) {
                tmp[1] = vec[0];
            } else if(idx == len-1) {
                if(vec[idx] > x) {
                    tmp[0] = vec[idx-1];
                    tmp[1] = vec[idx];
                } else tmp[0] = vec[idx];
            } else {
                tmp[0] = vec[idx-1];
                tmp[1] = vec[idx];
            }

            res.push_back(tmp);
        }

        return res;
    }

    int bsearch(int l, int r, int target) {
        while (l < r) {
            int mid = (l + r) >> 1;
            if (vec[mid] < target) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
