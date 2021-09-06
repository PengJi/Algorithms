/**
 * 5849. 好子集的数目
 * https://leetcode-cn.com/problems/the-number-of-good-subsets/
 */

typedef long long LL;

const int MOD = 1e9 + 7;

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/1742883/

    int s[31] = {0};
    int g[31][31] = {0};
    int st[31] = {0};
    vector<int> path;
    int C = 1;

    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    int dfs(int u, int sum) {
        if (!sum) return 0;
        if (u > 30) {
            if (path.empty()) return 0;
            return sum * (LL)C % MOD;
        }

        int res = dfs(u + 1, sum);
        if (!st[u]) {
            bool flag = true;
            for (auto x: path)
                if (g[x][u]) {
                    flag = false;
                    break;
                }

            if (flag) {
                path.push_back(u);
                res = (res + dfs(u + 1, sum * (LL)s[u] % MOD)) % MOD;
                path.pop_back();
            }
        }
        return res;
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        for (auto x: nums) s[x] ++ ;
        for (int i = 0; i < s[1]; i ++ ) C = C * 2 % MOD;

        for (int i = 2; i * i <= 30; i ++ )
            for (int j = 1; j * i * i <= 30; j ++ )
                st[j * i * i] = 1;

        for (int i = 1; i <= 30; i ++ )
            for (int j = 1; j <= 30; j ++ )
                if (gcd(i, j) > 1)
                    g[i][j] = 1;

        return dfs(2, 1);
    }
};
