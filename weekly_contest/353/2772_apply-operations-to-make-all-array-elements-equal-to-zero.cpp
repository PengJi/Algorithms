/**
 * https://leetcode.cn/problems/apply-operations-to-make-all-array-elements-equal-to-zero/description/
*/

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        const int n = nums.size();

        int sum = 0;
        for (int i = 0; i < n - k + 1; i++) {
            if (i >= k)
                sum -= nums[i - k];

            if (nums[i] < sum)
                return false;

            nums[i] -= sum;
            sum += nums[i];
        }

        for (int i = n - k + 1; i < n; i++) {
            if (i >= k)
                sum -= nums[i - k];

            if (nums[i] != sum)
                return false;
        }

        return true;
    }
};
