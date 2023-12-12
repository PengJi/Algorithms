/**
 * 2870. 使数组为空的最少操作次数
 * https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-empty/description/
*/
class Solution {
public:
    // 贪心
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int x : nums)
            ++seen[x];

        int ans = 0;
        for (const auto &[_, v] : seen) {
            if (v == 1)
                return -1;

            ans += v / 3 + (bool)(v % 3);
        }

        return ans;
    }
};
