/**
 * 974. 和可被 K 整除的子数组
 * 给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。
 * 
 * https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/
 */

class Solution {
public:
    // 前缀和 + 哈希表
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int subarraysDivByK(vector<int>& A, int K) {
        if(A.size() == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0, sum = 0, key = 0;
        for(auto num : A) {
            sum += num;
            key = (sum % K + K) % K;
            res += mp[key];
            mp[key]++;
        }

        return res;
    }

    // 前缀和 + 哈希表
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> record = {{0, 1}};
        int sum = 0;
        for (int elem: A) {
            sum += elem;
            // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            int modulus = (sum % K + K) % K;
            ++record[modulus];
        }

        int ans = 0;
        for (auto [x, cx]: record) {
            ans += cx * (cx - 1) / 2;
        }
        return ans;
    }
};
