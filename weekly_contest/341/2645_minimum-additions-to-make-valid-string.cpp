/**
 * 2645. 构造有效字符串的最少插入数
 * https://leetcode.cn/problems/minimum-additions-to-make-valid-string/description/
*/
class Solution {
public:
    // 思维题
    int addMinimum(string word) {
        const int n = word.size();

        int t = 1;
        for (int i = 0; i < n - 1; i++)
            if (word[i + 1] <= word[i])
                t++;

        return 3 * t - n;
    }
};
