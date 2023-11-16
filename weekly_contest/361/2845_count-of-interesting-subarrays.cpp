/**
 * 2845. 统计趣味子数组的数目
 * https://leetcode.cn/problems/count-of-interesting-subarrays/description/
*/
#define LL long long

class Solution {
public:
    LL countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> seen;
        int cnt = 0;
        LL ans = 0;

        seen[0] = 1;
        for (int x : nums) {
            cnt += (x % modulo == k);
            ans += seen[(cnt - k + modulo) % modulo];
            ++seen[cnt % modulo];
        }

        return ans;
    }
};
