/**
 * 581. 最短无序连续子数组
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
 */

class Solution {
public:
    // 最简洁做法
    // O(n)/O(1)
    // https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/shi-jian-chao-guo-100de-javajie-fa-by-zackqf/
    // 同时从前往后和从后往前遍历，分别得到要排序数组的右边界和左边界；
    // 
    // 寻找右边界：
    // 从前往后遍历的过程中，用max记录遍历过的最大值，如果max大于当前的nums[i]，说明nums[i]的位置不正确，属于需要排序的数组，
    // 因此将右边界更新为i，然后更新max；
    // 这样最终可以找到需要排序的数组的右边界，右边界之后的元素都大于max；
    // 
    // 寻找左边界：
    // 从后往前遍历的过程中，用min记录遍历过的最小值，如果min小于当前的nums[j]，说明nums[j]的位置不正确，应该属于需要排序的数组，
    // 因此将左边界更新为j，然后更新min；
    // 这样最终可以找到需要排序的数组的左边界，左边界之前的元素都小于min；
    // （从前往后遍历和从后往前遍历两个过程可以分两次循环完成，也可以放一起完成，这样的话就有：j=len-i-1）
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
