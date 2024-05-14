/**
 * 88. 合并两个有序数组
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
    // 从右向左合并
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;  // 填充末尾
        int i = m - 1, j = n - 1;
        while(i >= 0 && j >= 0) {  // 从右向左合并
            if(nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }

        while(j >= 0) nums1[k--] = nums2[j--];
    }
};
