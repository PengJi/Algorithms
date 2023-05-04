class Solution {
public:
    // 动态规划
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        const int mod = 1000000007;
        const int n = types.size();

        vector<int> f(target + 1, 0);
        f[0] = 1;

        for (int i = 0; i < n; i++)
            for (int j = target; j >= 0; j--)
                for (int k = 1; k <= types[i][0] && j >= k * types[i][1]; k++)
                    f[j] = (f[j] + f[j - k * types[i][1]]) % mod;

        return f[target];
    }
};
