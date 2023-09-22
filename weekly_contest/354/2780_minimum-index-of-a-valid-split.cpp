/**
 * 2780. 合法分割的最小下标
 * https://leetcode.cn/problems/minimum-index-of-a-valid-split/description/
*/
class Solution {
public:
    // 哈希表
    int minimumIndex(vector<int>& nums) {
        const int n = nums.size();

        unordered_map<int, int> seen;
        for (int x : nums)
            ++seen[x];

        int x, tot;
        for (const auto &[k, v] : seen)
            if (2 * v > n) {
                x = k;
                tot = v;

                break;
            }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x)
                ++cnt;

            if (2 * cnt > i + 1 && 2 * (tot - cnt) > n - i - 1)
                return i;
        }

        return -1;
    }
};
