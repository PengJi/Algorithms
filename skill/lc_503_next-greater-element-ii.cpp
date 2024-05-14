/**
 * 503. 下一个更大元素 II
 * https://leetcode.cn/problems/next-greater-element-ii/description/
 */

class Solution {
public:
    // 单调栈
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;

        for (int i = 0; i < n * 2; i++) {  // 拉直循环数组
            while (!stk.empty() && nums[i % n] > nums[stk.top()]) {
                res[stk.top()] = nums[i % n];
                stk.pop();
            }

            stk.push(i % n);
        }

        return res;
    }
};
