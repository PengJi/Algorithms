/**
 * 133. 克隆图
 * https://leetcode-cn.com/problems/clone-graph/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> hash;

    // https://www.acwing.com/activity/content/code/content/400699/
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        dfs(node);  // 复制所有点

        for (auto [s, d]: hash) {
            for (auto ver: s->neighbors)
                d->neighbors.push_back(hash[ver]);
        }

        return hash[node];
    }

    void dfs(Node* node) {
        hash[node] = new Node(node->val);

        for (auto ver: node->neighbors)
            if (hash.count(ver) == 0)
                dfs(ver);
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> hash;

    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        dfs(node);  // 复制所有点

        for (auto [s, d]: hash) {
            for (auto ver: s->neighbors)
                d->neighbors.push_back(hash[ver]);
        }

        return hash[node];
    }

    void dfs(Node* node) {
        hash[node] = new Node(node->val);

        for (auto ver: node->neighbors)
            if (hash.count(ver) == 0)
                dfs(ver);
    }
};
