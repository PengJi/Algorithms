/**
 * 2478. 完美分割的方案数
 * https://leetcode.cn/problems/number-of-beautiful-partitions/
*/
const int N = 1010, MOD = 1e9 + 7;

class Solution {
public:
    int f[N][N];

    int beautifulPartitions(string s, int k, int len) {
        int n = s.size();
        s = ' ' + s;
        set<char> s1{'2', '3', '5', '7'};
        f[0][0] = 1;
        for (int i = 1; i <= k; i ++ ) {
            int sum = 0;
            for (int j = 1; j <= n; j ++ ) {
                if (j >= len && s1.count(s[j - len + 1]))
                    sum = (sum + f[i - 1][j - len]) % MOD;
                if (!s1.count(s[j])) f[i][j] = sum;
            }
        }
        return f[k][n];
    }
};
