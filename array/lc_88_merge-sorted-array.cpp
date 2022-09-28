/**
 * 88. 合并两个有序数组
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 * 
 * https://leetcode-cn.com/problems/merge-sorted-array/
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = nums1.size()-1;
        m--;
        n--;
        while(n >= 0) {
            while(m >= 0 && nums1[m] > nums2[n]) {
                swap(nums1[idx--], nums1[m--]);
            }
            nums1[idx--] = nums2[n--];
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        int i = m - 1, j = n - 1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }

        while(j >= 0) nums1[k--] = nums2[j--];
    }
};
