/**
 * 14. 最长公共前缀
 * https://leetcode-cn.com/problems/longest-common-prefix/
 */

class Solution {
public:
    // 遍历，遍历每个字符串
    // 时间复杂度：O(n)，n为所有字符串长度之和
    // 空间复杂度：O(1)
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0) return "";

        string ans = strs[0];
        for (int i = 1; i < len; i++) {
            int j = 0;
            for (; j < ans.size() && j < strs[i].size(); j++) {
                if (ans[j] != strs[i][j]) break;
            }
            ans = ans.substr(0, j);
            if (ans.equal("")) return ans;
        }

        return ans;
    }

    // 排序
    // https://leetcode-cn.com/problems/longest-common-prefix/solution/jin-bi-jiao-liang-ge-zi-fu-chuan-14zui-chang-gong-/
    // 时间复杂度：O(nlogn + m)，n为字符串数组的长度，m为最短字符串的长度
    // 空间复杂度：O(1)
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (strs.empty()) return "";

        // 排序
        sort(strs.begin(), strs.end());

        // 比较最短和最长的字符串
        for (int i = 0; i < min(strs[0].size(), strs[n - 1].size()); ++i) {
            if (strs[0][i] != strs[n - 1][i]) return strs[0].substr(0, i);
        }

        return strs[0];
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        string res;
        for (int i = 0;; i++) {
            if (i >= strs[0].size()) return res;

            char c = strs[0][i];  // 以第一个字符串为基准，依次对比后面的字符串
            for (auto str : strs) {
                if (i >= str.size() || str[i] != c) return res;
            }
            res += c;
        }

        return res;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int n = strs.size();
        if (n == 0) return res;

        int idx = 0;
        while (true) {
            char c = strs[0][idx];

            int i = 0;
            for (; i < n; i++) {
                if (idx == strs[i].size() || strs[i][idx] != c) break;
            }
            if (i != n) return res;

            res += c;
            idx++;
        }
    }
};
