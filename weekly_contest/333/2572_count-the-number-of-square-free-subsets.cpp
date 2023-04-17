const int N = 10;

class Solution {
public:
    // 状态压缩动态规划
    int squareFreeSubsets(vector<int>& nums) {
        const int n = nums.size();
        const int mod = 1000000007;

        const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int f[1 << N];

        memset(f, 0, sizeof(f));

        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1], k = 0;
            bool ok = true;

            for (int j = 0; j < N; j++) {
                if (x % (p[j] * p[j]) == 0) {
                    ok = false;

                    break;
                }

                if (x % p[j] == 0)
                    k |= 1 << j;
            }

            if (!ok)
                continue;

            for (int j = (1 << N) - 1; j >= 0; j--)
                if ((j & k) == k)
                    f[j] = (f[j] + f[j ^ k]) % mod;
        }

        int ans = 0;
        for (int j = 0; j < (1 << N); j++)
            ans = (ans + f[j]) % mod;

        return (ans - 1 + mod) % mod;
    }
};
