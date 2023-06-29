/**
 * 2680. 最大或值
 * https://leetcode.cn/problems/maximum-or/
*/
#define LL long long

class Solution {
public:
    // 贪心
    LL maximumOr(vector<int>& nums, int k) {
        const int n = nums.size();

        vector<LL> suf(n);
        suf[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] | nums[i + 1];

        LL pre = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, pre | ((LL)(nums[i]) << k) | suf[i]);
            pre |= nums[i];
        }

        return ans;
    }
};
