/**
 * 2826. 将三个组排序
 * https://leetcode.cn/problems/sorting-three-groups/description/
*/
class Solution {
public:
    // 动态规划
    int minimumOperations(vector<int>& nums) {
        const int n = nums.size();
        int f1 = 1, f2 = 1, f3 = 1;

        if (nums[0] == 1) f1 = 0;
        else if (nums[0] == 2) f2 = 0;
        else f3 = 0;

        for (int i = 1; i < n; i++) {
            int t1 = f1 + (nums[i] != 1);
            int t2 = min(f1, f2) + (nums[i] != 2);
            int t3 = min(f1, min(f2, f3)) + (nums[i] != 3);
            f1 = t1; f2 = t2; f3 = t3;
        }

        return min(f1, min(f2, f3));
    }
};
