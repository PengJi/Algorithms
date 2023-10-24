/**
 * 2824. 统计和小于目标的下标对数目
 * https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/description/
*/
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        const int n = nums.size();

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (nums[i] + nums[j] < target)
                    ++ans;

        return ans;
    }
};
