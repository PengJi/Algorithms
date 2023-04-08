class Solution {
public: 
    long long count(vector<int>& nums, int k) // return the number of elements that are smaller than k
    {
        long long res = 0;
        for (int i = 0, j = nums.size() - 1; i < j; i ++ ) 
        {
            while (i < j && (long long)nums[i] + nums[j] > k) j --;
            res += j - i;
        }
        return res;
    }

    // 排序 + 双指针
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return count(nums, upper) - count(nums, lower - 1);
    }
};
