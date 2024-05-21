/**
 * 167. 两数之和 II - 输入有序数组
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 */

class Solution {
public:
    // 双指针
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> res;
        int cur;

        while (left < right) {
            cur = numbers[left] + numbers[right];
            if (cur < target) {
                left++;
            } else if (cur > target) {
                right--;
            } else {
                res.push_back(left + 1);
                res.push_back(right + 1);
                break;
            }
        }

        return res;
    }
};
