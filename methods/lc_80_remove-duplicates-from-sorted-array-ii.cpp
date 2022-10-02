/**
 * 80. 删除排序数组中的重复项 II
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/164/
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int removeDuplicates(vector<int>& nums) {
        int ans=0;
        for(auto x : nums) {
            if(ans < 2 || nums[ans-1] != x || nums[ans-2] != x) {  // 判断是否有效
                nums[ans++] = x; 
            }
        }

        return ans;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;  // 有效索引
        for(auto x: nums) {
            if(k < 2 || nums[k-2] != x) {
                nums[k++] = x;  // 有效数字增长
            }
        }

        return k;
    }
};
