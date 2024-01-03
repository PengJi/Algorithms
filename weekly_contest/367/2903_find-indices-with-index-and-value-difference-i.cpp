/**
 * 2903. 找出满足差值条件的下标 I
 * https://leetcode.cn/problems/find-indices-with-index-and-value-difference-i/description/
*/
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference,
        int valueDifference
    ) {
        const int n = nums.size();

        for (int i = 0; i < n; i++)
            for (int j = i + indexDifference; j < n; j++)
                if (abs(nums[i] - nums[j]) >= valueDifference)
                    return {i, j};

        return {-1, -1};
    }
};
