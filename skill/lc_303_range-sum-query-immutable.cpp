/**
 * 303. 区域和检索 - 数组不可变
 * https://leetcode-cn.com/problems/range-sum-query-immutable/
 */

class NumArray {
public:
    vector<int> vec;

    // 前缀和
    NumArray(vector<int>& nums) {
        vec.resize(nums.size() + 1);
        for (int i = 1; i <= nums.size(); i++) {
            vec[i] = vec[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int left, int right) {
        return vec[++right] - vec[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
