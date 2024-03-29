/**
 * 429. N叉树的层序遍历
 * https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
 */

/**
 * Definition for a Node.
 * class Node {
 * public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    // 广度优先遍历
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<vector<int>> levelOrder(Node *root) {
        if (root == NULL) {
            return vector<vector<int>>();
        }

        vector<vector<int>> res;
        queue<Node *> curLevel;
        curLevel.push(root);

        while (!curLevel.empty()) {
            int levelSize = curLevel.size();
            vector<int> tmpLevel;

            // 遍历当前层
            for (int i = 0; i < levelSize; i++) {
                Node *tmp = curLevel.front();
                tmpLevel.push_back(tmp->val);
                curLevel.pop();  // 将节点抛出

                // 将子节点加入队列
                for (auto childNode : tmp->children) {
                    curLevel.push(childNode);
                }
            }

            res.push_back(tmpLevel);
        }

        return res;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            int len = q.size();
            vector<int> tmp;
            Node *cur;

            while (len--) {
                cur = q.front();
                q.pop();
                tmp.push_back(cur->val);

                for (auto i : cur->children) {
                    q.push(i);
                }
            }

            res.emplace_back(tmp);
        }

        return res;
    }
};
