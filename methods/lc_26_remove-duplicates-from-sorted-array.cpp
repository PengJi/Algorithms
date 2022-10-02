/**
 * 26. 删除排序数组中的重复项
 * 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 * 
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;

        int i = 0;
        for(int j = 1; j < len; j++) {
            if(nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }

        return i + 1;
    }
};

class Solution {
public:
    // 双指针
    int removeDuplicates(vector<int>& nums) {
        int  k = 0;  // 有效数字索引
        for(int i = 0; i < nums.size(); i++) {
            if(!i || nums[i] != nums[i-1]) {  // 排除第一个元素，其他元素只要不相等则为有效数字
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};
