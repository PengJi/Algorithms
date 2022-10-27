/**
 * 214. 最短回文串
 * https://leetcode-cn.com/problems/shortest-palindrome/
 */

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/426412/
    string shortestPalindrome(string s) {
        string t(s.rbegin(), s.rend());
        int n = s.size();
        s = ' ' + s + '#' + t;
        vector<int> ne(n * 2 + 2);
        for (int i = 2, j = 0; i <= n * 2 + 1; i ++ ) {
            while (j && s[i] != s[j + 1]) j = ne[j];
            if (s[i] == s[j + 1]) j ++ ;
            ne[i] = j;
        }
        int len = ne[n * 2 + 1];
        string left = s.substr(1, len), right = s.substr(1 + len, n - len);
        return string(right.rbegin(), right.rend()) + left + right;
    }
};

class Solution {
public:
    // kmp 算法，待深入
    // 大体思路是求最长回文前缀，得到最长回文前缀后，便可得到得到需要添加的子字符串
    // 将字符串逆序拼接到原字符串的末尾，然后使用 kmp 算法
    string shortestPalindrome(string s) {
        int n = s.size();

        // 逆序拼接到原字符串的末尾
        string t(s.rbegin(), s.rend());
        string str(s + "#" + t);

        // 新字符串
        vector<int> nxt(2 * n + 1);

        int j = -1;
        nxt[0] = -1;

        // kmp 算法
        for (int i = 1; i < 2 * n + 1; i++) {
            while (j > -1 && str[j + 1] != str[i]) j = nxt[j];
            if (str[j + 1] == str[i])
                j++;

            nxt[i] = j;
        }

        return t.substr(0, n - nxt[2 * n] - 1) + s;
    }
};
