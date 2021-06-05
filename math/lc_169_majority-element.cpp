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
