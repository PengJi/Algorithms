/**
 * 239. 滑动窗口最大值
 * https://leetcode-cn.com/problems/sliding-window-maximum/
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            // 滑动窗口的大小
            if(!dq.empty() && i - dq.front() >= k) dq.pop_front();

            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();

            dq.push_back(i);

            if(i >= k-1) res.push_back(nums[dq.front()]);
        }

        return res;
    }
};
