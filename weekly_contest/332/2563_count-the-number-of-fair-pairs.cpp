typedef long long LL;

class Solution {
public: 
    LL count(vector<int>& nums, int k) // return the number of elements that are smaller than k
    {
        LL res = 0;
        for (int i = 0, j = nums.size() - 1; i < j; i ++ ) 
        {
            while (i < j && (LL)nums[i] + nums[j] > k) j --;
            res += j - i;
        }
        return res;
    }

    // 排序 + 双指针
    LL countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return count(nums, upper) - count(nums, lower - 1);
    }
};
