/**
 * 2470. 最小公倍数为 K 的子数组数目
 * https://leetcode.cn/problems/number-of-subarrays-with-lcm-equal-to-k/description/
*/
class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    // 暴力法
    // 枚举以每个元素为起点的数组
    int subarrayLCM(vector<int>& nums, int k) {
        int len  = nums.size();
        int res = 0;
        for(int i = 0; i < len; i++) {
            int l = nums[i];
            
            for(int j = i; j < len; j++) {
                l = l * nums[j] / gcd(l ,nums[j]);
                if(l == k) res++;
                else if (l > k) break;
            }
        }

        return res;
    }
};
