/**
 * 438. 找到字符串中所有字母异位词
 * https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
 */

class Solution {
public:
    // 双指针滑动窗口
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> mp;
        for (auto& c : p) mp[c]++;  // 统计滑动窗口中的元素个数
        int tot = mp.size(), ret = 0;

        int j = 0;                            // 左指针
        for (int i = 0; i < s.size(); i++) {  // 右指针
            mp[s[i]]--;                       // 在窗口中的元素减一
            if (mp[s[i]] == 0) ret++;         // 满足条件的元素个数

            if (i - j + 1 > p.size()) {
                if (mp[s[j]] == 0) ret--;  // 之前满足，现在不满足了
                mp[s[j++]]++;              // 不在窗口中的元素加一
            }

            if (ret == tot) res.push_back(j);  // 满足条件
        }

        return res;
    }
};
