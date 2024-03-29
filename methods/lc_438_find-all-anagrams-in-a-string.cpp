/**
 * 438. 找到字符串中所有字母异位词
 * 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
 * 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
 * 
 * https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
 */

class Solution {
public:
    // 滑动窗口
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> findAnagrams(string s, string t) {
        unordered_map<char, int> need, window;
        for(char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        vector<int> res;  // 记录结果

        while(right < s.size()) {
            char c = s[right];
            right++;

            // 进行窗口内数据的一系列更新
            if(need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            // 判断左侧窗口是否要收缩
            while(right - left >= t.size()) {
                // 当窗口符合条件时，把起始索引加入 res
                if(valid == need.size())
                    res.push_back(left);
                char d = s[left];
                left++;

                // 进行窗口内数据的一系列更新
                if(need.count(d)) {
                    if(window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }

        return res;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> mp;
        for(auto c : p) mp[c]++;
        int tot = mp.size(), st = 0;
        for(int i = 0, j = 0; i < s.size(); i++) {
            if(--mp[s[i]] == 0) st++;
            if(i - j + 1 > p.size()) {
                if(mp[s[j]] == 0) st--;
                mp[s[j++]]++;
            }
            if(tot == st) res.push_back(j);
        }

        return res;
    }
};
