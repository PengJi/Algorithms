/**
 * 5751. 下标对中的最大距离
 * https://leetcode-cn.com/problems/maximum-distance-between-a-pair-of-values/
 */

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        for(int j = nums2.size()-1, i = nums1.size()-1; j >= 0; j--) {
            while(i && nums1[i-1] <= nums2[j]) i--;
            if(nums1[i] <= nums2[j]) res = max(res, j-i);
        }

        return res;
    }
};