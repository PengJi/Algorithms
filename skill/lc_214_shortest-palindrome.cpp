/**
 * 214. 最短回文串
 * https://leetcode-cn.com/problems/shortest-palindrome/
 */

class Solution {
public:
    // https://www.acwing.com/activity/content/problem/content/2582/
    // 贪心 +  KMP
    // 求字符串 s 的最长回文前缀，然后剩余的部分就可以逆序拼接到 s 的最前边得到一个回文串。
    // 例如 abcbabcab 的最长回文前缀是 abcba，则答案就是 bacb + abcba + bcab = bacbabcbabcab。
    // 首先将原串逆序复制一份，得到字符串 t。
    // 将 s + # + t 作为新字符串，求其 next 数组。
    // 假设下标从 0 开始，则最后位置上的 next 值加 1 就是最长回文前缀的长度，假设重合长度为 l。
    // 最终答案为 t[0:l] + s。
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
