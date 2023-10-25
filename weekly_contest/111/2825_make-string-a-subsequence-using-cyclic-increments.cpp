/**
 * 2825. 循环增长使字符串子序列等于另一个字符串
 * https://leetcode.cn/problems/make-string-a-subsequence-using-cyclic-increments/description/
*/
class Solution {
private:
    bool valid(char a, char b) {
        return a == b || a == (b - 'a' + 1) % 26 + 'a';
    }

public:
    // 双指针
    bool canMakeSubsequence(string str1, string str2) {
        const int n = str1.size(), m = str2.size();
        if (n < m)
            return false;

        for (int i = 0, j = 0; i < m; i++) {
            while (j < n && !valid(str2[i], str1[j]))
                j++;

            if (j == n)
                return false;

            j++;
        }

        return true;
    }
};
