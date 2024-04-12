/**
 * 3. 无重复字符的最长子串
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 */

class Solution {
public:
    // 滑动窗口
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char> st;
        int left;

        for (int i = 0; i < s.size(); i++) {
            while (st.count(s[i]) != 0) {
                st.erase(s[left]);
                left++;
            }
            res = max(res, i - left + 1);
            st.insert(s[i]);
        }

        return res;
    }
};

class Solution {
public:
    // 暴力法（左右指针）
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    int lengthOfLongestSubstring(string s) {
        int length = s.size();
        if (length == 0) return 0;

        int left = 0, right = 0, next = 1, max = 1;
        while (right < length && next < length) {
            for (int i = left; i <= right; i++) {
                if (s[i] == s[next]) {
                    left = i + 1;
                }
            }

            if (left > right) {
                right = left;
                next++;
            } else {
                right = next;
                next++;
            }

            if ((right - left + 1) > max) {
                max = right - left + 1;
            }
        }

        return max;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            mp[s[i]]++;
            while (mp[s[i]] > 1) mp[s[j++]]--;
            res = max(res, i - j + 1);
        }

        return res;
    }
};
