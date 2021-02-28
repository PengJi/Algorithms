/**
 * 剑指 Offer 11. 旋转数组的最小数字
 * https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
 */

class Solution {
public:
    // 二分查找
    // 时间复杂度：O(logn)
    // 空间复杂度：O(1)
    int minArray(vector<int>& numbers) {
        int low = 0, high = numbers.size()-1;
        int pivot;
        while(low < high) {
            pivot = low + (high-low)/2;
            if(numbers[pivot] < numbers[high]) {
                high = pivot;
            } else if(numbers[pivot] > numbers[high]) {
                low = pivot + 1;
            } else {
                high -= 1;
            }
        }

        return numbers[low];
    }
};
