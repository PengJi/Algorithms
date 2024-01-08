/**
 * 2905. 找出满足差值条件的下标 II
 * https://leetcode.cn/problems/find-indices-with-index-and-value-difference-ii/description/
*/
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference,
        int valueDifference
    ) {
        const int n = nums.size();

        int ma = INT_MIN, ma_x = -1;
        int mi = INT_MAX, mi_x = -1;
        for (int i = indexDifference; i < n; i++) {
            if (ma < nums[i - indexDifference]) {
                ma = nums[i - indexDifference];
                ma_x = i - indexDifference;
            }
            if (mi > nums[i - indexDifference]) {
                mi = nums[i - indexDifference];
                mi_x = i - indexDifference;
            }

            if (nums[i] - ma <= -valueDifference)
                return {ma_x, i};

            if (nums[i] - mi >= valueDifference)
                return {mi_x, i};
        }

        return {-1, -1};
    }
};
