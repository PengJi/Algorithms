/**
 * 137. 只出现一次的数字 II
 * https://leetcode-cn.com/problems/single-number-ii/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetcode/
    int singleNumber(vector<int>& nums) {
        // first appearence: 
        // add num to seen_once 
        // don't add to seen_twice because of presence in seen_once

        // second appearance: 
        // remove num from seen_once 
        // add num to seen_twice

        // third appearance: 
        // don't add to seen_once because of presence in seen_twice
        // remove num from seen_twice
        int once = 0, twice = 0;
        for(auto num : nums) {
            once = ~twice & (once ^ num);
            twice = ~once & (twice ^ num);
        }

        return once;
    }
};
