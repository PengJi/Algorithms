/**
 * 2784. 检查数组是否是好的
 * https://leetcode.cn/problems/check-if-array-is-good/description/
*/
class Solution {
public:
    // 哈希表
    bool isGood(vector<int>& nums) {
        const int n = nums.size() - 1;

        vector<int> seen(n + 1, 0);
        for (int x : nums) {
            if (x > n)
                return false;

            ++seen[x];
        }

        for (int i = 1; i < n; i++)
            if (seen[i] != 1)
                return false;

        return seen[n] == 2;
    }
};
