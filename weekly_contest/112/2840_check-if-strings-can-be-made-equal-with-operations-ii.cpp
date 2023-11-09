/**
 * 2840. 判断通过操作能否让字符串相等 II
 * https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/
*/
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        const int n = s1.size();

        int seen[2][26];
        memset(seen, 0, sizeof(seen));

        for (int i = 0; i < n; i++) {
            ++seen[i % 2][s1[i] - 'a'];
            --seen[i % 2][s2[i] - 'a'];
        }

        for (int i = 0; i < 26; i++)
            if (seen[0][i] != 0 || seen[1][i] != 0)
                return false;

        return true;
    }
};
