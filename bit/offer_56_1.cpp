/**
 * 剑指 Offer 56 - I. 数组中数字出现的次数
 * https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
 */

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for(int n : nums) {
            ret ^= n;
        }

        int div = 1;
        while((div & ret) == 0) {  // 找到不为 0 的最低位
            div <<= 1;  // 左移一位
        }

        int a = 0, b = 0;
        for(int n : nums) {  // 分为两组，两个数分别在不同组
            if(div & n) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        return vector<int>{a, b};
    }
};
