/**
 * https://leetcode.cn/problems/longest-non-decreasing-subarray-from-two-arrays/description/
*/

class Solution {
public:
    // 动态规划
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();

        int f = 1, g = 1, ans = 1;

        for (int i = 1; i < n; i++) {
            int nf = 1, ng = 1;

            if (nums1[i] >= nums1[i - 1])
                nf = max(nf, f + 1);

            if (nums1[i] >= nums2[i - 1])
                nf = max(nf, g + 1);

            if (nums2[i] >= nums1[i - 1])
                ng = max(ng, f + 1);

            if (nums2[i] >= nums2[i - 1])
                ng = max(ng, g + 1);

            f = nf; g = ng;
            ans = max(ans, max(f, g));
        }

        return ans;
    }
};
