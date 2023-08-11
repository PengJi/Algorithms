/**
 * 2736. 最大和查询
 * https://leetcode.cn/problems/maximum-sum-queries/description/
*/

class Solution {
private:
    int m;
    vector<int> f;

    void add(int x, int y) {
        for (; x <= m; x += x & -x)
            f[x] = max(f[x], y);
    }

    int query(int x) {
        int ma = -1;
        for (; x; x -= x & -x)
            ma = max(ma, f[x]);

        return ma;
    }

public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2,
        vector<vector<int>>& queries
    ) {
        const int n = nums1.size();
        const int q = queries.size();

        vector<int> seen;
        for (int x : nums2)
            seen.push_back(x);

        for (const auto &q : queries)
            seen.push_back(q[1]);

        sort(seen.begin(), seen.end());
        m = unique(seen.begin(), seen.end()) - seen.begin();
        seen.resize(m);
        f.resize(m + 1, -1);

        vector<int> mp(m);
        for (int i = 0; i < m; i++)
            mp[i] = seen[i];

        for (int i = 0; i < n; i++)
            nums2[i] = lower_bound(seen.begin(), seen.end(), nums2[i]) - seen.begin();

        for (int i = 0; i < q; i++)
            queries[i][1] = lower_bound(seen.begin(), seen.end(), queries[i][1])
                - seen.begin();

        vector<int> o1(n);
        iota(o1.begin(), o1.end(), 0);
        sort(o1.begin(), o1.end(), [&](int x, int y) {
            return nums1[x] > nums1[y];
        });

        vector<int> oq(q);
        iota(oq.begin(), oq.end(), 0);
        sort(oq.begin(), oq.end(), [&](int x, int y) {
            return queries[x][0] > queries[y][0];
        });

        vector<int> ans(q);
        for (int i = 0, j = 0; i < q; i++) {
            while (j < n && nums1[o1[j]] >= queries[oq[i]][0]) {
                add(m - nums2[o1[j]], nums1[o1[j]] + mp[nums2[o1[j]]]);
                ++j;
            }

            ans[oq[i]] = query(m - queries[oq[i]][1]);
        }

        return ans;
    }
};
