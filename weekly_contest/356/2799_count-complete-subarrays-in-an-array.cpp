/**
 * 2799. 统计完全子数组的数目
 * https://leetcode.cn/problems/count-complete-subarrays-in-an-array/description/
*/
class Solution {   
public:
    // 双指针
    int countCompleteSubarrays(vector<int>& nums) {
        const int n = nums.size();
        unordered_set<int> tot(nums.begin(), nums.end());

        unordered_map<int, int> seen;
        int cnt = 0, ans = 0;

        for (int i = 0, j = 0; i < n; i++) {
            ++seen[nums[i]];
            if (seen[nums[i]] == 1)
                ++cnt;

            while (cnt == tot.size()) {
                --seen[nums[j]];
                if (seen[nums[j]] == 0)
                    --cnt;
                ++j;
            }

            ans += j;
        }

        return ans;
    }
};
