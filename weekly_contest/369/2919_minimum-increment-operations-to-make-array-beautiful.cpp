/**
 * 2919. 使数组变美的最小增量运算数
 * https://leetcode.cn/problems/minimum-increment-operations-to-make-array-beautiful/description/
*/
#define LL long long

class Solution {
public:
    LL minIncrementOperations(vector<int>& nums, int k) {
        const int n = nums.size();

        LL f0 = max(0, k - nums[2]);
        LL f1 = max(0, k - nums[1]);
        LL f2 = max(0, k - nums[0]);

        for (int i = 3; i < n; i++) {
            LL t0 = min(f0, min(f1, f2)) + max(0, k - nums[i]);
            LL t1 = f0;
            LL t2 = f1;

            f0 = t0; f1 = t1; f2 = t2;
        }

        return min(f0, min(f1, f2));
    }
};
