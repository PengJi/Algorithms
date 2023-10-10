/**
 * 2808. 使循环数组所有元素相等的最少秒数
 * https://leetcode.cn/problems/minimum-seconds-to-equalize-a-circular-array/description/
*/
class Solution {
public:
    // 哈希表
    int minimumSeconds(vector<int>& nums) {
        const int n = nums.size();

        unordered_map<int, vector<int>> v;

        for (int i = 0; i < n; i++)
            v[nums[i]].push_back(i);

        int ans = n / 2;

        for (const auto &[_, v] : v) {
            int m = n + v[0] - v.back();

            for (int i = 0; i < v.size() - 1; i++)
                m = max(m, v[i + 1] - v[i]);

            ans = min(ans, m / 2);
        }

        return ans;
    }
};
