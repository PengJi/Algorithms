/**
 * 567. 字符串的排列
 * https://leetcode-cn.com/problems/permutation-in-string/
 */

class Solution {
public:
    // 滑动窗口
    // https://leetcode-cn.com/problems/permutation-in-string/solution/wo-xie-liao-yi-shou-shi-ba-suo-you-hua-dong-chuang/
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char c : s1) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char c = s2[right];
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            // 判断左侧窗口是否要收缩
            while (right - left >= s1.size()) {
                // 在这里判断是否找到了合法的子串
                if (valid == need.size())
                    return true;
                char d = s2[left];
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        // 未找到符合条件的子串
        return false;
    }
};

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
