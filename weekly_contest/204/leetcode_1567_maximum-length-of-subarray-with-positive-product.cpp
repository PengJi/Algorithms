/**
 * 1567. 乘积为正数的最长子数组长度
 * https://leetcode-cn.com/problems/maximum-length-of-subarray-with-positive-product/
 */

class Solution {
public:
    int getMaxLen(vector<int>& nums) {

    }
};

    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int pos = 0, neg = 0;
        for (int num: nums) {
            if (num == 0) {
                pos = neg = 0;
            } else if (num > 0) {
                ++pos;
                if (neg > 0) {
                    ++neg;
                }
            } else {
                int newpos = (neg > 0 ? neg + 1 : 0);
                int newneg = (pos > 0 ? pos + 1 : 1);
                pos = newpos;
                neg = newneg;
            }
            ans = max(ans, pos);
        }
        return ans;
    }