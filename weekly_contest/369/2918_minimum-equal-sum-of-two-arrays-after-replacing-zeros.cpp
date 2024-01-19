/**
 * 2918. 数组的最小相等和
 * https://leetcode.cn/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/
*/
#define LL long long

class Solution {
public:
    LL minSum(vector<int>& nums1, vector<int>& nums2) {
        LL tot1 = 0, tot2 = 0;
        int z1 = 0, z2 = 0;

        for (int x : nums1) {
            if (x == 0)
                ++z1;
            tot1 += x;
        }

        for (int x : nums2) {
            if (x == 0)
                ++z2;
            tot2 += x;
        }

        if (z1 == 0 && z2 == 0)
            return tot1 == tot2 ? tot1 : -1;

        if (z1 == 0)
            return tot2 + z2 <= tot1 ? tot1 : -1;

        if (z2 == 0)
            return tot1 + z1 <= tot2 ? tot2 : -1;

        return max(tot1 + z1, tot2 + z2);
    }
};
