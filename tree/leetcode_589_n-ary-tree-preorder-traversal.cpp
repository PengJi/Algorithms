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
    // 迭代
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        
        stack<Node *> stk;
        stk.push(root);
        while(!stk.empty()){
            Node* curNode = stk.top();
            stk.pop();
            res.push_back(curNode->val);
            
            for(int i=curNode->children.size()-1; i>=0; i--){
                if(curNode->children[i] != nullptr){
                    stk.push(curNode->children[i]);
                }
            }
        }
        
        return res;
    }
    
    // 递归
    vector<int> preorder1(Node* root) {
        vector<int> res;
        travel(root, res);
        return res;
    }

    void travel(Node* node, vector<int>& res){
        if(node == nullptr){
            return;
        }
        
        res.push_back(node->val);
        
        for(Node* child : node->children){
            travel(child, res);
        }
    }
};