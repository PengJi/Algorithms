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
        if (root == NULL) return 0;

        int res = 0;
        queue<pair<TreeNode*, unsigned long>> que;  // 记录节点与位置
        que.push({root, 1});
        TreeNode* node;
        int len;
        unsigned long pos;

        while (!que.empty()) {
            len = que.size();
            res = max(res, int(que.back().second - que.front().second + 1));

            for (int i = 0; i < len; i++) {
                node = que.front().first;
                pos = que.front().second;
                que.pop();

                if (node->left) que.push({node->left, 2 * pos});
                if (node->right) que.push({node->right, 2 * pos + 1});
            }
        }

        return res;
    }
};

typedef long long LL;

class Solution {
public:
    // 层序遍历
    // 对整个树进行层级遍历。遍历时，记录每一层所有结点的编号。
    // 编号规则如下，根结点编号为 0。某个结点的左儿子结点编号为当前结点的编号乘 2；右儿子结点的编号为当前结点的编号乘 2 再加 1。
    // 遍历完一层后，我们进行编号收缩，以最小编号作为偏移量，让当前层所有编号都减去这个偏移量，然后再进行遍历编号。
    // 通过编号收缩，保证编号的范围不会超过答案，所以不会
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<TreeNode*, LL>> vec;
        if(root) vec.emplace_back(root, 0);
        LL res = 0;

        while(!vec.empty()) {
            LL offset = vec.front().second;
            LL len = vec.size();
            // 缩减范围
            for(int i = 0; i < len; i++) {
                vec[i].second -= offset;
            }

            res = max(res, vec.back().second + 1);
            
            vector<pair<TreeNode*, LL>> tmp;
            for(int i = 0; i < len; i++) {
                TreeNode* node = vec[i].first;
                LL pos = vec[i].second;

                if(node->left) tmp.emplace_back(node->left, pos << 1);
                if(node-> right) tmp.emplace_back(node->right, pos << 1 | 1);
            }

            vec = tmp;
        }

        return res;
    }
};
