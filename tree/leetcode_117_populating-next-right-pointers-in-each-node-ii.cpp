/**
 * 117. 填充每个节点的下一个右侧节点指针 II
 * https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/
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
    // https://www.acwing.com/solution/content/206/
    Node* connect(Node* root) {
        Node* head = root;
        while(root) {  // 遍历每一层
            Node* dummy = new Node(0);
            Node* cur = dummy;
            while(root) {  // 按层遍历，将下层节点依次入队列
                if(root->left) {  // 左子结点入队列
                    cur->next = root->left;
                    cur = cur->next;
                }
                if(root -> right) {  // 右子结点入队列
                    cur->next = root->right;
                    cur = cur->next;
                }
                root = root->next;
            }
            root = dummy->next;  // 下一层的队首结点
        }

        return head;
    }
};
