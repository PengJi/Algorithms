/**
 * 239. 滑动窗口最大值
 * https://leetcode-cn.com/problems/sliding-window-maximum/
 */

class Solution {
public:
    // 单调队列
    // 使用单调队列求解滑动窗口中的最大值。
    // 其中，单调队列是一个普通的双端队列，即队头和队尾都可以添加和弹出元素。
    // 我们假设该双端队列的 队头 是整个队列的最大元素所在下标，至 队尾 下标代表的元素值依次降低。
    // 初始时单调队列为空。随着对数组的遍历过程中，每次插入元素前，需要考察两个事情：
    // (1). 合法性检查：队头下标如果距离 i 超过了 k ，则应该出队。
    // (2). 单调性维护：如果 nums[i] 大于或等于队尾元素下标所对应的值，则当前队尾再也不可能充当某个滑动窗口的最大值了，
    //      故需要队尾出队。始终保持队中元素从队头到队尾单调递减。
    // 如次遍历一遍数组，队头就是每个滑动窗口的最大值所在下标。
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
