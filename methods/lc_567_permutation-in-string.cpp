/**
 * 567. 字符串的排列
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 * 换句话说，第一个字符串的排列之一是第二个字符串的子串。
 * 
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
    unordered_map<char, int> m1, m2;

    bool check(char a) {
        if(m1.count(a) && m1[a] == m2[a]) return true;
        return false;
    }

    bool checkInclusion(string s1, string s2) {
        for(auto& x : s1) m1[x]++;
        for(int i = 0, j = 0, cnt = 0; i < s2.size(); i++) {
            if(check(s2[i])) cnt--;
            m2[s2[i]]++;
            if(check(s2[i])) cnt++;

            if(i - j >= s1.size()) {
                if(check(s2[j])) cnt--;
                m2[s2[j]]--;
                if(check(s2[j])) cnt++;
                j++;
            }
            if(cnt == m1.size()) return true;
        }

        return false;
    }
};

