/**
 * 503. 下一个更大元素 II
 * https://leetcode.cn/problems/next-greater-element-ii/description/
 */

class Solution {
public:
    // 单调栈
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        stack<int> stk;
        vector<int> res(len, -1);

        for (int i = 0; i < len * 2 - 1; i++) {  // 拉直循环数组
            while (!stk.empty() && nums[stk.top()] < nums[i % len]) {
                res[stk.top()] = nums[i % len];
                stk.pop();
            }

            stk.push(i % len);
        }

        return res;
    }
};
