/**
 * 239. 滑动窗口最大值
 * https://leetcode-cn.com/problems/sliding-window-maximum/
 */

class Solution {
public:
    // 双端队列
    // TODO 待优化
    // https://leetcode-cn.com/problems/sliding-window-maximum/solution/shuang-xiang-dui-lie-jie-jue-hua-dong-chuang-kou-z/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==0)return {};
        vector<int>res;
        deque<size_t>window;
        /*Init K integers in the list*/
        for (size_t i = 0; i < k; i++) {
            while (!window.empty()  && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        res.push_back(nums[window.front()]);
        /*End of initialization*/
        for (size_t i = k; i < nums.size(); i++) {
            if (!window.empty() && window.front() <= i - k) {
                window.pop_front();
            }
            while (!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
            res.push_back(nums[window.front()]);
        }
        return res;
    }
};