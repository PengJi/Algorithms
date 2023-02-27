/**
 * 2521. 数组乘积中的不同质因数数目
 * https://leetcode.cn/problems/distinct-prime-factors-of-product-of-array/
*/

class Solution {
public:
    // 分解质因数
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto x: nums) {
            for (int i = 2; i * i <= x; i ++ ) {
                if (x % i == 0) {
                    hash.insert(i);
                    while (x % i == 0) x /= i;
                }
            }
            if (x > 1) hash.insert(x);
        }

        return hash.size();
    }
};
