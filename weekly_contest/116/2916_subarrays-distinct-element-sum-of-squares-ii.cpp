/**
 * 2916. 子数组不同元素数目的平方和 II
 * https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-ii/description/
*/
#define LL long long

const int N = 100010;
const int mod = 1000000007;

class Solution {
    int sum[N << 2], mark[N << 2];

    void pushdown(int rt, int len) {
        if (mark[rt] == 0)
            return;

        mark[rt << 1] = (mark[rt << 1] + mark[rt]) % mod;
        sum[rt << 1] = (sum[rt << 1] + (LL)(mark[rt]) * (len - (len >> 1))) % mod;
        mark[rt << 1 | 1] = (mark[rt << 1 | 1] + mark[rt]) % mod;
        sum[rt << 1 | 1] = (sum[rt << 1 | 1] + (LL)(mark[rt]) * (len >> 1)) % mod;
        mark[rt] = 0;
    }

    void pushup(int rt) {
        sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % mod;
    }

    void update(int L, int R, int l, int r, int rt, int p) {
        if (L <= l && r <= R) {
            sum[rt] = (sum[rt] + p * (r - l + 1)) % mod;
            mark[rt] = (mark[rt] + p) % mod;

            return;
        }

        pushdown(rt, r - l + 1);

        int mid = (l + r) >> 1;
        if (L <= mid) update(L, R, l, mid, rt << 1, p);
        if (mid < R) update(L, R, mid + 1, r, rt << 1 | 1, p);

        pushup(rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R)
            return sum[rt];

        pushdown(rt, r - l + 1);

        int mid = (l + r) >> 1, tot = 0;
        if (L <= mid) tot = (tot + query(L, R, l, mid, rt << 1)) % mod;
        if (mid < R) tot = (tot + query(L, R, mid + 1, r, rt << 1 | 1)) % mod;

        return tot;
    }

public:
    int sumCounts(vector<int>& nums) {
        const int n = nums.size();
        int sqr = 0, ans = 0;

        unordered_map<int, int> seen;

        memset(sum, 0, sizeof(sum));
        memset(mark, 0, sizeof(mark));

        for (int i = 0; i < n; i++) {
            int prev = -1;
            if (seen.find(nums[i]) != seen.end())
                prev = seen[nums[i]];

            sqr = (sqr + 2 * query(prev + 1, i, 0, n - 1, 1) % mod + i - prev) % mod;

            update(prev + 1, i, 0, n - 1, 1, 1);
            ans = (ans + sqr) % mod;

            seen[nums[i]] = i;
        }

        return ans;
    }
};
