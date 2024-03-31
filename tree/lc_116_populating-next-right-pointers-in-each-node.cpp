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
        if (root == NULL) return NULL;
        Node* cur = root;
        Node* tmp;
        while (cur->left) {
            tmp = cur;
            while (tmp) {
                tmp->left->next = tmp->right;
                if (tmp->next)
                    tmp->right->next = tmp->next->left;
                else
                    tmp->right->next = NULL;

                tmp = tmp->next;
            }

            cur = cur->left;
        }

        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* head = root;  // 当前层的首结点
        while (head) {
            Node* next_head = nullptr;  //记录下一层的首结点
            if (head->left) {
                next_head = head->left;
            } else {
                break;
            }

            for (Node* p = head; p != nullptr; p = p->next) {
                p->left->next = p->right;  // 左结点的下一个结点
                if (p->next) {
                    p->right->next = p->next->left;  // 右结点的下一个结点
                }
            }

            head = next_head;  // 遍历下一层
        }

        return root;
    }
};
