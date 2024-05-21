/**
 * 974. 和可被 K 整除的子数组
 * https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/
 */

class Solution {
public:
    // 前缀和 + 哈希表
    // 如果我们求出了前缀和数组 s，如果原数组区间 [j, i] 能被 K 整除，
    // 则 (s[i] - s[j - 1]) mod K == 0，即 s[j - 1] mod K == s[i] mod K。
    // 只需要记录 i 之前，有多少位置的 s[j] 在模 K 后的值和 s[i] mod K 相等，这就需要用一个哈希表。
    // O(n)/O(1)
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0, sum = 0, key = 0;

        for (auto num : A) {
            sum += num;
            key = (sum % K + K) % K;  // 注意：C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            res += mp[key];
            mp[key]++;
        }

        return res;
    }
};
