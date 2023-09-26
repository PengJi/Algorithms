/**
 * 2786. 访问数组中的位置使分数最大
 * https://leetcode.cn/problems/visit-array-positions-to-maximize-score/description/
*/
#define LL long long

class Solution {
public:
    // 动态规划
    LL maxScore(vector<int>& nums, int x) {
        const LL INF = 1000000000000ll;
        const int n = nums.size();

        LL f = -INF, g = -INF;

        if (nums[0] % 2 == 0) f = nums[0];
        else g = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == 0) f = max(f, g - x) + nums[i];
            else g = max(f - x, g) + nums[i];
        }

        return max(f, g);
    }
};
