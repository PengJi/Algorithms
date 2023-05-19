typedef long long LL;

class Solution {
public:
    vector<LL> minOperations(vector<int>& nums, vector<int>& queries) {
        const int n = nums.size();
        const int m = queries.size();

        sort(nums.begin(), nums.end());

        vector<LL> sum(n);

        sum[0] = nums[0];
        for (int i = 1; i < n; i++)
            sum[i] = sum[i - 1] + nums[i];

        vector<LL> ans(m, 0);
        for (int i = 0; i < m; i++) {
            int x = queries[i];
            int p = lower_bound(nums.begin(), nums.end(), x) - nums.begin();

            ans[i] += sum[n - 1] - (p > 0 ? sum[p - 1] : 0) - (LL)(x) * (n - p);
            if (p > 0)
                ans[i] += (LL)(x) * p - sum[p - 1];
        }

        return ans;
    }
};
