/**
 * 215. 数组中的第K个最大元素
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 */

class Solution {
public:
    // 快排
    // 时间复杂度：O(nlogn)
    // 空间复杂度：O(logn)
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 0) return 0;
        quickSort(nums, 0, len-1);
        return nums[k-1];
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if(low < high) {
            int mid = partition(nums, low, high);
            quickSort(nums, low, mid-1);
            quickSort(nums, mid+1, high);
        }
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];

        while(low < high) {
            while(low < high && nums[high] <= pivot) {
                high--;
            }
            nums[low] = nums[high];

            while(low < high && nums[low] >= pivot) {
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }

    // 暴力法
    // 时间复杂度：O(nlogn)
    // 空间复杂度：O(1)
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        sort(begin(nums), end(nums));
        return nums[size - k];
    }
};
