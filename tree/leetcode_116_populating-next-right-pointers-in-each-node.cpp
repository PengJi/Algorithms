/**
 * 116. 填充每个节点的下一个右侧节点指针
 * https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // https://www.acwing.com/solution/content/204/
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        Node* cur = root;
        Node* tmp;
        while(cur->left) {
            tmp = cur;
            while(tmp) {
                tmp->left->next = tmp->right;
                if(tmp->next) tmp->right->next = tmp->next->left;
                else tmp->right->next = NULL;

                tmp = tmp->next;
            }

            cur = cur->left;
        }

        return root;
    }
};

