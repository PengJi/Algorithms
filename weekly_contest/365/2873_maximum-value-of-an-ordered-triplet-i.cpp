/**
 * 2873. 有序三元组中的最大值 I
 * https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-i/description/
*/
#define LL long long

class Solution {
public:
    LL maximumTripletValue(vector<int>& nums) {
        const int n = nums.size();

        LL ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    ans = max(ans, (LL)(nums[i] - nums[j]) * nums[k]);

        return ans;
    }
};
