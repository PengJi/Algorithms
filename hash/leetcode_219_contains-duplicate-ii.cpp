/**
 * 219. 存在重复元素 II
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，
 * 使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。
 *
 * https://leetcode-cn.com/problems/contains-duplicate-ii/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/contains-duplicate-ii/solution/hua-jie-suan-fa-219-cun-zai-zhong-fu-yuan-su-ii-by/
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> st;

        for(int i = 0; i < nums.size(); i++) {
            if(st.count(nums[i]) != 0) {
                return true;
            }

            st.insert(nums[i]);

            if(st.size() > k) {
                st.erase(nums[i - k]);
            }
        }

        return false;
    }
};
