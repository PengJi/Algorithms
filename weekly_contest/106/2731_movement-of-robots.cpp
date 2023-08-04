/**
 * 2731. 移动机器人
 * https://leetcode.cn/problems/movement-of-robots/description/
*/

#define LL long long

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        const int n = nums.size();
        const int mod = 1000000007;

        vector<LL> pos(n);
        for (int i = 0; i < n; i++)
            if (s[i] == 'L') pos[i] = nums[i] - d;
            else pos[i] = nums[i] + d;

        sort(pos.begin(), pos.end());

        int ans = 0;
        for (int i = 1; i < n; i++) {
            LL d = pos[i] - pos[i - 1];
            ans = (ans + d * i % mod * (n - i) % mod) % mod;
        }

        return ans;
    }
};
