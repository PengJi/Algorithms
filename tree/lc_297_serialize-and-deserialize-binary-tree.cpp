/**
 * 297. 二叉树的序列化与反序列化
 * https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/solution/er-cha-shu-de-xu-lie-hua-yu-fan-xu-lie-hua-by-le-2/
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root) return "X";
        auto l = "(" + serialize(root->left) + ")";
        auto r = "(" + serialize(root->right) + ")";
        return l + to_string(root->val) + r;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        int ptr = 0;
        return parse(data, ptr);
    }

    TreeNode *parse(const string &data, int &ptr) {
        if (data[ptr] == 'X') {
            ++ptr;
            return nullptr;
        }
        auto cur = new TreeNode(0);
        cur->left = parseSubtree(data, ptr);
        cur->val = parseInt(data, ptr);
        cur->right = parseSubtree(data, ptr);
        return cur;
    }

    inline TreeNode *parseSubtree(const string &data, int &ptr) {
        ++ptr;  // 跳过左括号
        auto subtree = parse(data, ptr);
        ++ptr;  // 跳过右括号
        return subtree;
    }

    inline int parseInt(const string &data, int &ptr) {
        int x = 0, sgn = 1;
        if (!isdigit(data[ptr])) {
            sgn = -1;
            ++ptr;
        }
        while (isdigit(data[ptr])) {
            x = x * 10 + data[ptr++] - '0';
        }
        return x * sgn;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
