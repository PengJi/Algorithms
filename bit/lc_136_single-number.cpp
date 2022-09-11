/**
 * 136. 只出现一次的数字
 * https://leetcode-cn.com/problems/single-number/
 */

class Solution {
public:
    // 位运算
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto n : nums){
            res ^= n;
        }

        return res;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto n: nums) res ^= n;
        return res;
    }
};
