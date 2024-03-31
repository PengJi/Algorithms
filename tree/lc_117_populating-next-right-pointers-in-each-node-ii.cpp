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
    // O(n)
    // O(1)
    Node* connect(Node* root) {
        Node* head = root;

        while (root) {  // 遍历每一层
            Node* dummy = new Node(0);
            Node* cur = dummy;
            while (root) {         // 按层遍历，将下层节点依次入队列
                if (root->left) {  // 左子结点入队列
                    cur->next = root->left;
                    cur = cur->next;
                }
                if (root->right) {  // 右子结点入队列
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

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* head = root;
        while (head) {  // 当前层的首结点
            Node* last = nullptr;  // 当前层中某个结点的上一个结点
            Node* ns = nullptr;    // 下一层的首结点

            for (Node* p = head; p != nullptr; p = p->next) {
                if (p->left) {                       // 右结点做同样处理
                    if (!ns) ns = p->left;           // 下一层的首结点
                    if (last) last->next = p->left;  // 修改上个结点的 next 指针
                    last = p->left;                  // 记录上一个结点
                }
                if (p->right) {
                    if (!ns) ns = p->right;
                    if (last) last->next = p->right;
                    last = p->right;
                }
            }
            head = ns;
        }

        return root;
    }
};
