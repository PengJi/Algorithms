/**
 * 2896. 执行操作使两个字符串相等
 * https://leetcode.cn/problems/apply-operations-to-make-two-strings-equal/description/
*/
class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        if (count(s1.begin(), s1.end(), '1') % 2 != count(s2.begin(), s2.end(), '1') % 2) {
            return -1;
        }
        int n = s1.length();
        int memo[n][n + 1][2];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, bool)> dfs = [&](int i, int j, bool pre_rev) -> int {
            if (i < 0) {
                return j || pre_rev ? INT_MAX / 2 : 0;
            }
            int &res = memo[i][j][pre_rev];
            if (res != -1) {
                return res;
            }
            if ((s1[i] == s2[i]) == !pre_rev) {
                return dfs(i - 1, j, false);
            }
            res = min(dfs(i - 1, j + 1, false) + x, dfs(i - 1, j, true) + 1);
            if (j) {
                res = min(res, dfs(i - 1, j - 1, false));
            }
            return res;
        };
        return dfs(n - 1, 0, false);
    }
};
