/**
 * 2856. 删除数对后的最小数组长度
 * https://leetcode.cn/problems/minimum-array-length-after-pair-removals/description/
*/
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        const int n = nums.size();

        int x = nums[n / 2];
        int ma = upper_bound(nums.begin(), nums.end(), x) -
            lower_bound(nums.begin(), nums.end(), x);

        return max(2 * ma - n, n & 1);
    }
};
