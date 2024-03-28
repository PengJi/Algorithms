/**
 * 589. N叉树的前序遍历
 * https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/
 */

/*
class Node {
public:
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
public:
    // 递归
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> preorder1(Node* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(Node* node, vector<int>& res) {
        if (!node) return;
        res.push_back(node->val);

        for (Node* child : node->children) {
            traverse(child, res);
        }
    }
};

class Solution {
public:
    // 迭代
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<Node*> stk;
        stk.push(root);

        while (!stk.empty()) {
            Node* cur = stk.top();
            stk.pop();
            res.push_back(cur->val);

            for (int i = cur->children.size() - 1; i >= 0; i--) {
                if (cur->children[i] != nullptr) {
                    stk.push(cur->children[i]);
                }
            }
        }

        return res;
    }
};
