/**
 * 5471. 和为目标值的最大数目不重叠非空子数组数目
 * https://leetcode-cn.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
 */

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int sum = 0, ans = 0;
        set<int> s;
        s.insert(0);

        for(auto i : nums) {
            sum += i;
            if(s.find(sum - target) != s.end()) {
                ans++;
                sum = 0;
                s.clear();
            }
            s.insert(sum);
        }

        return ans;
    }
};
