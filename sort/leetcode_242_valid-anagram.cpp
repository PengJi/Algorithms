/**
 * 242. 有效的字母异位词
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * https://leetcode-cn.com/problems/valid-anagram/
 */

class Solution {
public:
    // 排序
    // 时间复杂度：O(nlogn)
    // 空间复杂度：O(nlogn)
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    // 哈希思想（推荐）
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int count[26] = {0}
        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(int i = 0; i<26; i++){
            if(count[i]) return false;
        }

        return true;
    }
};