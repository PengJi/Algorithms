/**
 * 31. 下一个排列
 * https://leetcode-cn.com/problems/next-permutation/
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = len - 2, j = len - 1, k = len - 1;

        while(j >= 0 && nums[i] >= nums[j]) {
            i--;
            j--;
        }

        if(i >= 0) {
            while(nums[i] >= nums[k]) {
                k--;
            }
            int tmp = nums[k];
            nums[k] = nums[i];
            nums[i] = tmp;
        }

        for(i = j, j = len - 1; i < j; i = i+1, j = j-1) {
            int tmp = nums[j];
            nums[j] = nums[i];
            nums[i] = tmp;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

    if len(nums) <= 1 {
        return
    }

    i, j, k := len(nums)-2, len(nums)-1, len(nums)-1

    // find: A[i]<A[j]
    for i >= 0 && nums[i] >= nums[j] {
        i--
        j--
    }

    if i >= 0 { // 不是最后一个排列
        // find: A[i]<A[k]
        for nums[i] >= nums[k] {
            k--
        }
        // swap A[i], A[k]
        nums[i], nums[k] = nums[k], nums[i]
    }

    // reverse A[j:end]
    for i, j := j, len(nums)-1; i < j; i, j = i+1, j-1 {
        nums[i], nums[j] = nums[j], nums[i]
    }