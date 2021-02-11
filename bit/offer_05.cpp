/**
 * 剑指 Offer 15. 二进制中1的个数
 * https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        
        while(n != 0) {
            n &= n-1;  // 执行一次，去除一个1
            ans++;
        }

        return ans;
    }
};
