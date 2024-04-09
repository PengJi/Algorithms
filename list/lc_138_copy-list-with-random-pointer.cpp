/**
 * 138. 复制带随机指针的链表
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) return 0;
        unordered_map<Node *, Node *> hash;
        Node *root = new Node(head->val, NULL, NULL);
        hash[head] = root;
        while (head->next) {
            if (hash.count(head->next) == 0)
                hash[head->next] = new Node(head->next->val, NULL, NULL);
            hash[head]->next = hash[head->next];

            if (head->random && hash.count(head->random) == 0)
                hash[head->random] = new Node(head->random->val, NULL, NULL);
            hash[head]->random = hash[head->random];

            head = head->next;
        }

        if (head->random && hash.count(head->random) == 0)
            hash[head->random] = new Node(head->random->val, NULL, NULL);
        hash[head]->random = hash[head->random];

        return root;
    }
};
