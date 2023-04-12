class Solution {
public:
    // 贪心
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min(nums[n - 2] - nums[1], min(nums[n - 3] - nums[0], nums[n- 1] - nums[2]));
    }
};
