/**
 * 5698. 构成特定和需要添加的最少元素
 * https://leetcode-cn.com/problems/minimum-elements-to-add-to-form-a-given-sum/
 */

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long cur_sum=0;
        for(int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
        }

        long goal_sum = abs(goal - cur_sum);
        if(goal_sum % limit == 0) {
            return goal_sum/limit;
        } else {
            return goal_sum/limit+1;
        }
    }
};
