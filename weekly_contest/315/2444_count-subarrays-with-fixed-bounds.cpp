/**
 * 2444. 统计定界子数组的数目
 * https://leetcode.cn/problems/count-subarrays-with-fixed-bounds/
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int smin = 0, smax = 0;
        for (int i = 0, last = 0, j = 0; i < nums.size(); i ++ ) {
            if (nums[i] < minK || nums[i] > maxK) {
                j = last = i + 1;
                smin = smax = 0;
                continue;
            }

            if (nums[i] == minK) smin ++ ;
            if (nums[i] == maxK) smax ++ ;

            while (j <= i) {
                if (nums[j] == minK) smin -- ;
                if (nums[j] == maxK) smax -- ;
                if (!smin || !smax) {
                    if (nums[j] == minK) smin ++ ;
                    if (nums[j] == maxK) smax ++ ;
                    break;
                }
                j ++ ;
            }

            if (smin && smax) {
                res += j - last + 1;
            }
        }

        return res;
    }
};
