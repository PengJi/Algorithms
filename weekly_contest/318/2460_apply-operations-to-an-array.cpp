/**
 * 2460. 对数组执行操作
 * https://leetcode.cn/problems/apply-operations-to-an-array/description/
*/
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        const int n = nums.size();

        for (int i = 0; i < n - 1; i++)
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }

        int i = 0, j = 0;

        for (; i < n; i++) 
            if (nums[i] > 0)
                nums[j++] = nums[i];

        for (; j < n; j++)
            nums[j] = 0;

        return nums;
    }
};
