/**
 * 2926. 平衡子序列的最大和
 * https://leetcode.cn/problems/maximum-balanced-subsequence-sum/description/
*/
#define LL long long

const LL INF = 1000000000000000ll;

class Solution {
private:
    int m;
    vector<LL> f;

    void add(int x, LL y) {
        for (; x <= m; x += x & -x)
            f[x] = max(f[x], y);
    }

    LL query(int x) {
        LL r = -INF;

        for (; x; x -= x & -x)
            r = max(r, f[x]);

        return r;
    }

public:
    LL maxBalancedSubsequenceSum(vector<int>& nums) {
        const int n = nums.size();

        vector<int> t;
        for (int i = 0; i < n; i++)
            t.push_back(nums[i] - i);

        sort(t.begin(), t.end());
        m = unique(t.begin(), t.end()) - t.begin();
        t.resize(m);

        f.resize(m + 1, -INF);

        LL ans = -INF;
        for (int i = 0; i < n; i++) {
            int pos = lower_bound(t.begin(), t.end(), nums[i] - i) - t.begin() + 1;
            LL s = max((LL)(nums[i]), query(pos) + nums[i]);
            ans = max(ans, s);
            add(pos, s);
        }

        return ans;
    }
};
