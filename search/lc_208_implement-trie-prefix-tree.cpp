/**
 * 208. 实现 Trie (前缀树)
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/#/description
 */

class Trie {
public:
    // https://leetcode.com/problems/implement-trie-prefix-tree/discuss/58868/Implement-Trie-(Prefix-Tree)-C%2B%2B-Clean-Code-(array-or-map)

    Trie* next[26] = {};
    bool isword = false;

    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->next[ch]) {
                node->next[ch] = new Trie();
            }
            node = node->next[ch];
        }
        node->isword = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->next[ch]) {
                return false;
            }
            node = node->next[ch];
        }
        return node->isword;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (!node->next[ch]) {
                return false;
            }
            node = node->next[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
