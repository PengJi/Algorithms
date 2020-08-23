/**
 * 5481. 得到目标数组的最少函数调用次数
 * https://leetcode-cn.com/problems/minimum-numbers-of-function-calls-to-make-target-array/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/minimum-numbers-of-function-calls-to-make-target-array/solution/c-shuang-bai-er-jin-zhi-chao-jian-dan-chao-hao-li-/
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int max_num = 0;  // 记录最大的数
        for(auto n : nums) {
            if(n > max_num) max_num = n;
            while(n > 0) {
                if(n & 1) ans++;  // 统计奇数
                n /= 2;
            }
        }

        // 除 2 的次数
        while(max_num > 0) {
            max_num /= 2;
            ans++;
        }

        return ans - 1;
    }
};
