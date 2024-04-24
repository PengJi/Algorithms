/**
 * 581. 最短无序连续子数组
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
 */

class Solution {
public:
    // 最简洁做法
    // O(n)/O(1)
    // https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/shi-jian-chao-guo-100de-javajie-fa-by-zackqf/
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int right_bound = nums[0], left_bound = nums[len - 1];
        int left = 0, right = -1;
        for (int i = 0; i < len; i++) {
            if (right_bound > nums[i]) {
                right = i;
            } else {
                right_bound = nums[i];
            }

            if (left_bound < nums[len - i - 1]) {
                left = len - i - 1;
            } else {
                left_bound = nums[len - i - 1];
            }
        }

        return right - left + 1;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l + 1 < n && nums[l] <= nums[l + 1]) l++;
        if (l == r) return 0;
        while (r - 1 >= 0 && nums[r] >= nums[r - 1]) r--;

        for (int i = l + 1; i < n; i++) {
            while (l >= 0 && nums[i] < nums[l]) l--;
        }
        for (int j = r - 1; j >= 0; j--) {
            while (r < n && nums[j] > nums[r]) r++;
        }

        return r - l - 1;
    }
};
