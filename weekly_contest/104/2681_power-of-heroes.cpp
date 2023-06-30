/**
 * 2681. 英雄的力量
 * https://leetcode.cn/problems/power-of-heroes/
*/
typedef long long LL;

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        const int n = nums.size();
        const int mod = 1000000007;

        sort(nums.begin(), nums.end());

        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + (LL)(nums[i]) * nums[i] % mod * (sum + nums[i])) % mod;
            sum = ((LL)(sum) * 2 % mod + nums[i]) % mod;
        }

        return ans;
    }
};
