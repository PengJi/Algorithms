/**
 * 剑指 Offer 56 - II. 数组中数字出现的次数 II
 * https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/mian-shi-ti-56-ii-shu-zu-zhong-shu-zi-chu-xian-d-4/
    int singleNumber(vector<int>& nums) {
        int ones = 0. twos = 0;
        for(int num: nums) {
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }

        return ones;
    }
};
