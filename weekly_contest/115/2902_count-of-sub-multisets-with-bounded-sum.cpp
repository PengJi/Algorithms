/**
 * 2902. 和带限制的子多重集合的数目
 * https://leetcode.cn/problems/count-of-sub-multisets-with-bounded-sum/description/
*/
#define LL long long

const int N = 20010;

class Solution {
private:
    int f[N], cnt[N], t[N], s[N];

public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        const int mod = 1000000007;
        const int n = nums.size();

        for (int i = 0; i < n; i++)
            ++cnt[nums[i]];

        f[0] = 1;
        int sum = 0;
        for (int i = 1; i < N; i++) {
            if (cnt[i] == 0)
                continue;

            sum += cnt[i] * i;

            for (int j = 0; j <= min(r, sum); j++) {
                if (j / i == 0)
                    s[j % i] = 0;

                t[j] = f[j];
                f[j] = (f[j] + s[j % i]) % mod;
                s[j % i] = (s[j % i] + t[j]) % mod;

                if (j >= i * cnt[i])
                    s[j % i] = (s[j % i] - t[j - i * cnt[i]] + mod) % mod;
            }
        }

        int ans = 0;
        for (int i = l; i <= r; i++)
            ans = (ans + f[i]) % mod;

        return (LL)(ans) * (cnt[0] + 1) % mod;
    }
};
