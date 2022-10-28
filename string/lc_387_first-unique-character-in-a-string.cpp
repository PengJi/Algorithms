/**
 * 387. 字符串中的第一个唯一字符
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/
 */

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(26, 0);
        for(int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a']++;
        }

        for(int i = 0; i < s.size(); i++) {
            if(arr[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};

class Solution {
public:
    // 使用哈希表
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(auto c: s) mp[c]++;

        for(int i = 0; i < s.size(); i++) {
            if(mp[s[i]] == 1) return i;
        }

        return -1;
    }
};
