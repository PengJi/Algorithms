/**
 * 2762. 不间断子数组
 * https://leetcode.cn/problems/continuous-subarrays/description/
*/

#define LL long long

class Solution {
public:
    // 双指针，单调队列
    LL continuousSubarrays(vector<int>& nums) {
        const int n = nums.size();

        deque<int> mi, ma;
        LL ans = 0;

        for (int i = 0, j = 0; i < n; i++) {
            while (!mi.empty() && nums[mi.back()] >= nums[i]) mi.pop_back();
            while (!ma.empty() && nums[ma.back()] <= nums[i]) ma.pop_back();

            mi.push_back(i);
            ma.push_back(i);

            while (!mi.empty() && !ma.empty() && 
                nums[ma.front()] - nums[mi.front()] > 2
            ) {
                ++j;
                while (!mi.empty() && mi.front() < j) mi.pop_front();
                while (!ma.empty() && ma.front() < j) ma.pop_front();
            }

            ans += i - j + 1;
        }

        return ans;
    }
};
