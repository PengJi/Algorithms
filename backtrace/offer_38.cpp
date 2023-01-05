/**
 * 剑指 Offer 38. 字符串的排列
 * https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
 */

class Solution {
public:
    // 回溯法
    // https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/chui-su-z-by-zrita-gvc0/
    // 时间复杂度：O(n!)
    // 空间复杂度：O(n^2)
    vector<string> permutation(string s) {
        vector<string> ans;
        dfs(s, ans, 0);
        return ans;
    }

    void dfs(string &s, vector<string> &res, int depth) {
        if(depth >= s.size() - 1) {
            res.push_back(s);
            return;
        }

        unordered_set<char> used;
        for(int i = depth; i < s.size(); i++) {
            if(used.find(s[i]) != used.end()) continue;  // 去重
            used.insert(s[i]);
            swap(s[depth], s[i]);
            dfs(s, res, depth+1);
            swap(s[depth], s[i]);  // 撤销
        }
    }
};
