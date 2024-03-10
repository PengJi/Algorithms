/**
 * 260. 只出现一次的数字 III
 * https://leetcode-cn.com/problems/single-number-iii/
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ab = 0;
        for (auto x : nums) {
            ab ^= x;
        }

        int k = 0;
        while (((ab >> k) & 1) == 0) k++;

        int res1 = 0, res2 = 0;
        for (auto x : nums) {
            if (x >> k & 1)
                res1 ^= x;
            else
                res2 ^= x;
        }

        return {res1, res2};
    }
};
