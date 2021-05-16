/**
 * 5759. 找出所有子集的异或总和再求和
 * https://leetcode-cn.com/problems/sum-of-all-subset-xor-totals/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/49601/
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < 1 << n; i++) {
            int x = 0;
            for (int j =0; j < n; j++) {
                if (i >>j & 1) {
                    x ^= nums[j];
                }
            }
            ans += x;
        }
        return ans;
    }
};
