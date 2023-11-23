/**
 * 2855. 使数组成为递增数组的最少右移次数
 * https://leetcode.cn/problems/minimum-right-shifts-to-sort-the-array/description/
*/
class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        const int n = nums.size();

        int j = -1;
        for (int i = 1; i < n; i++)
            if (nums[i] < nums[i - 1]) {
                j = i;

                break;
            }

        if (j == -1)
            return 0;

        for (int i = j + 1; i < n; i++)
            if (nums[i] < nums[i - 1])
                return -1;

        if (nums[n - 1] > nums[0])
            return -1;

        return n - j;
    }
};
