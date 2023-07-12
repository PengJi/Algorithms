/**
 * 2698. 求一个整数的惩罚数
 * https://leetcode.cn/problems/find-the-punishment-number-of-an-integer
*/

class Solution {
public:
    bool check(int i, int sum, int remain, const string &s) {
        if (sum > remain)
            return false;

        if (i == s.size()) {
            if (remain == sum)
                return true;

            return false;
        }

        if (check(i + 1, sum * 10 + s[i] - '0', remain, s))
            return true;

        return check(i + 1, s[i] - '0', remain - sum, s);
    }

    // 递归回溯
    int punishmentNumber(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            string t = to_string(i * i);
            if (check(1, t[0] - '0', i, t))
                ans += i * i;
        }

        return ans;
    }
};
