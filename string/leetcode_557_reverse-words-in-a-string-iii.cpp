/**
 * 557. 反转字符串中的单词 III
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
 */

class Solution {
public:
    // 遍历
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    string reverseWords(string s) {
        if(s.size()== 0) return "";

        int left = 0, right = 0;
        int next;
        while(right < s.size()) {
            // 当前单词的右边界
            while(right < s.size() && s[right] != ' ') right++;
            int next = right + 1;
            right--;
            // 反转当前单词
            while(left < right) swap(s[left++], s[right--]); 
            
            // 下一个单词
            left = next;
            right = next;
        }

        return s;
    }
};
