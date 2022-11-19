/**
 * 2465. 不同的平均值数目
 * https://leetcode.cn/problems/number-of-distinct-averages/description/
*/
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<int> hash;
        sort(nums.begin(), nums.end());
        
        for (int i = 0, j = nums.size() - 1; i < j; i ++, j -- )
            hash.insert(nums[i] + nums[j]);
        return hash.size();
    }
};
