/**
 * 496. 下一个更大元素 I
 * https://leetcode.cn/problems/next-greater-element-i/description/
*/

class Solution {
public:
    // 哈希表 + 单调栈
    // 首先将 nums2 里的所有元素存入 unordered_map 中，方便确定 nums1 中元素在 nums2 中的位置。
    // 对 nums2 中的每个元素，需要求其右边第一个比其大的元素，这里可以用单调栈来实现。
    // 建立一个单调递减的栈，如果新入栈的元素比栈顶元素值要大，则栈顶出栈，直到不比栈顶元素大为止。
    // 栈顶出栈的过程中，就已经确定了其右边第一个比其大的元素就是最后要新入栈的元素。
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++)
            hash[nums[i]] = i;

        stack<int> st;
        vector<int> greater(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                greater[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) {
            greater[st.top()] = -1;
            st.pop();
        }

        int m = findNums.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++)
            ans[i] = greater[hash[findNums[i]]];

        return ans;
    }
};
