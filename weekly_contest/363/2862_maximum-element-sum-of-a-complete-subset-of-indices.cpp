/**
 * 2862. 完全子集的最大元素和
 * https://leetcode.cn/problems/maximum-element-sum-of-a-complete-subset-of-indices/description/
*/
class Solution {
    int core(int n) {
        int res = 1;
        for (int i = 2; i * i <= n; i++) {
            int e = 0;
            while (n % i == 0) {
                e ^= 1;
                n /= i;
            }
            if (e) {
                res *= i;
            }
        }
        if (n > 1) {
            res *= n;
        }
        return res;
    }

public:
    long long maximumSum(vector<int> &nums) {
        vector<long long> sum(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            sum[core(i + 1)] += nums[i];
        }
        return *max_element(sum.begin(), sum.end());
    }
};
