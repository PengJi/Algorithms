class Solution {
    const int MOD = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int f[n]; memset(f, 0, sizeof(f));
        f[0] = 1;
        int cnt_b = 0;
        for (int i = 0; i < n; ++i) {
            if (i + delay >= n) cnt_b = (cnt_b + f[i]) % MOD;
            for (int j = i + delay; j < min(i + forget, n); ++j)
                f[j] = (f[j] + f[i]) % MOD;
        }
        return (f[n - 1] + cnt_b) % MOD;
    }
};
