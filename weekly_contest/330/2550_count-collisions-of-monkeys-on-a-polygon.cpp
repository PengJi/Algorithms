#define LL long long

class Solution {
public:
    // 快速幂
    int monkeyMove(int n) {
        const int mod = 1000000007;

        int ans = 1;
        LL p = 2;
        for (; n; n >>= 1) {
            if (n & 1)
                ans = ans * p % mod;
            p = p * p % mod;
        }

        return (ans - 2 + mod) % mod;
    }
};
