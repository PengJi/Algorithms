/**
 * 169. 多数元素
 * https://leetcode-cn.com/problems/majority-element/
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mole_vote = 0, ans = 0;
        for(int i : nums){
            if(mole_vote == 0){
                ans = i;
            }
            mole_vote += ans == i ? 1 : -1;
        }
        return ans;
    }
};

class Solution {
public:
    // 投票算法
    // 时间复杂度和空间复杂度最小。
    int majorityElement(vector<int>& nums) {
        int cnt = 0, res = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(cnt == 0) res = nums[i];
            if(res == nums[i]) cnt++;
            else cnt--;
        }

        return res;
    }
};
