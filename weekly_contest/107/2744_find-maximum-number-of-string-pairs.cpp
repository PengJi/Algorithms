/**
 * 2744. 最大字符串配对数目
 * https://leetcode.cn/problems/find-maximum-number-of-string-pairs/description/
*/

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> seen;

        for (const auto &w : words)
            seen.insert(w);

        int ans = 0;
        for (const auto &w : words) {
            string w1(w.rbegin(), w.rend());

            if (w1 != w && seen.find(w1) != seen.end())
                ++ans;
        }

        return ans / 2;
    }
};
