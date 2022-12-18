/**
 * 268. 丢失的数字
 * https://leetcode-cn.com/problems/missing-number/
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n*(n+1)/2;
        for(auto x : nums) res -= x;
        return res;
    }
};

class Solution {
public:
    // 对数组的数字求和，然后求差值
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n * (n+1) / 2;
        for(auto x: nums) res -= x;
        return res;
    }
};
