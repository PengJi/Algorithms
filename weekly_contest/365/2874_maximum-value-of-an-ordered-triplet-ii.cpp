/**
 * 2874. 有序三元组中的最大值 II
 * https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-ii/description/
*/
#define LL long long

class Solution {
public:
    LL maximumTripletValue(vector<int>& nums) {
        const int n = nums.size();

        vector<int> minsuf(n), maxsuf(n);
        minsuf[n - 1] = maxsuf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minsuf[i] = min(minsuf[i + 1], nums[i]);
            maxsuf[i] = max(maxsuf[i + 1], nums[i]);
        }

        int minpre = nums[0], maxpre = nums[0];
        LL ans = 0;
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, (LL)(minpre - nums[i]) * minsuf[i + 1]);
            ans = max(ans, (LL)(maxpre - nums[i]) * maxsuf[i + 1]);
            minpre = min(minpre, nums[i]);
            maxpre = max(maxpre, nums[i]);
        }

        return ans;
    }
};
