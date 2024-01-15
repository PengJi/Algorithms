/**
 * 2914. 使二进制字符串变美丽的最少修改次数
 * https://leetcode.cn/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/
*/
class Solution {
public:
    int minChanges(string s) {
        const int n = s.size();

        int ans = 0;
        for (int i = 0; i < n; i += 2)
            ans += s[i] != s[i + 1];

        return ans;
    }
};
