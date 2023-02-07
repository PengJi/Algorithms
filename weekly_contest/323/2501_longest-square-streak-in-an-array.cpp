typedef long long LL;
const int N = 100010;

int f[N];

class Solution {
public:
    // 动态规划
    int longestSquareStreak(vector<int>& nums) {
        memset(f, 0, sizeof f);
        sort(nums.begin(), nums.end(), greater<int>());

        int res = 0;
        for (auto x: nums) {
            LL y = (LL)x * x;
            if (y < N)
                f[x] = f[y] + 1;
            else
                f[x] = 1;
            res = max(res, f[x]);
        }

        if (res < 2) res = -1;
        return res;
    }
};
