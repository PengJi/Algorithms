/**
 * 2640. 一个数组所有前缀的分数
 * https://leetcode.cn/problems/find-the-score-of-all-prefixes-of-an-array/
*/
typedef long long LL;

class Solution {
public:
    vector<LL> findPrefixScore(vector<int>& nums) {
        const int n = nums.size();

        int ma = 0;
        for (int i = 0; i < n; i++) {
            ma = max(ma, nums[i]);
            nums[i] += ma;
        }

        vector<LL> ans(n);
        ans[0] = nums[0];
        for (int i = 1; i < n; i++)
            ans[i] = ans[i - 1] + nums[i];

        return ans;
    }
};
