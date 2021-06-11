/**
 * 647. 回文子串
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 
 * https://leetcode-cn.com/problems/palindromic-substrings/
 */

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            palindromic(s, i, i, cnt);  //judge odd substring
            palindromic(s, i, i+1, cnt);  //judge even substring
        }
        return cnt;
    }
    
private:
    void palindromic(string s, int left, int right, int& cnt) { //judge if a substring is palindromic
        while(left >=0 && right < s.size() && s[left] == s[right]) {
            cnt++;
            left--;
            right++;
        }
    }
};
