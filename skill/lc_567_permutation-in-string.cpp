/**
 * 567. 字符串的排列
 * https://leetcode-cn.com/problems/permutation-in-string/
 */

class Solution {
public:
    // 滑动窗口
    // 与 438 算法相同
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for (auto& c : s1) mp[c]++;
        int tot = mp.size(), ret = 0;

        int j = 0;
        for (int i = 0; i < s2.size(); i++) {
            mp[s2[i]]--;  // 在滑动窗口中的元素个数减一
            if (mp[s2[i]] == 0) ret++;

            if (i - j + 1 > s1.size()) {  // 判断窗口大小
                if (mp[s2[j]] == 0) ret--;
                mp[s2[j++]]++;  // 不在滑动窗口中的元素加一
            }

            if (tot == ret) return true;
        }

        return false;
    }
};
