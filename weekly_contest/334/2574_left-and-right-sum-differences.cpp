class Solution {
public:
    // 后缀和
    vector<int> leftRightDifference(vector<int>& nums) {
        const int n = nums.size();
        vector<int> suf(n + 1);

        suf[n] = 0;
        for (int i = n - 1; i >= 0; i--)
            suf[i] = suf[i + 1] + nums[i];

        vector<int> ans(n);

        int pre = 0;
        for (int i = 0; i < n; i++) {
            ans[i] = abs(pre - suf[i + 1]);
            pre += nums[i];
        }

        return ans;
    }
};
