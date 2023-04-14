#define LL long long
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

const int N = 100010;

class Solution {
private:
    int sum[N << 2], lazy[N << 2];

    void build(int l, int r, int rt, const vector<int> &nums) {
        if (l == r) {
            sum[rt] = nums[l];

            return;
        }

        int mid = (l + r) >> 1;
        build(lson, nums);
        build(rson, nums);

        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }

    void modify(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) {
            lazy[rt] ^= 1;
            sum[rt] = r - l + 1 - sum[rt];

            return;
        }

        pushdown(r - l + 1, rt);

        int mid = (l + r) >> 1;
        if (L <= mid) modify(L, R, lson);
        if (mid < R) modify(L, R, rson);

        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }

    void pushdown(int len, int rt) {
        if (lazy[rt] == 0)
            return;

        int ls = rt << 1, rs = rt << 1 | 1;
        lazy[ls] ^= 1; lazy[rs] ^= 1;

        sum[ls] = len - (len >> 1) - sum[ls];
        sum[rs] = (len >> 1) - sum[rs];

        lazy[rt] = 0;
    }

public:
    vector<LL> handleQuery(vector<int>& nums1, vector<int>& nums2,
        vector<vector<int>>& queries
    ) {
        const int n = nums1.size();

        build(0, n - 1, 1, nums1);

        LL s = 0;
        for (int x : nums2)
            s += x;

        vector<LL> ans;
        for (const auto &q : queries) {
            int t = q[0];
            if (t == 1) modify(q[1], q[2], 0, n - 1, 1);
            else if (t == 2) s += (LL)(sum[1]) * q[1];
            else ans.push_back(s);
        }

        return ans;
    }
};
