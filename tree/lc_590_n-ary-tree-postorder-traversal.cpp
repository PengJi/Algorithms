/**
 * 590. N叉树的后序遍历
 * https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/
 */

/*
// Definition for a Node.
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
    vector<int> postorder(Node* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(Node* root, vector<int> &vec){
        if(root != NULL){
            for(auto i : root->children){
                traverse(i, vec);
            }

            vec.push_back(root->val);
        }
    }

    // 迭代
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<Node*> stk;
        stk.push(root);
        Node* cur;

        while(!stk.empty()){  // 按前序遍历
            cur = stk.top();
            res.push_back(cur->val);
            stk.pop();
            
            for(auto i : cur->children){
                stk.push(i);
            }
        }

        reverse(res.begin(), res.end());  // 反转顺序
        return res;
    }
};
