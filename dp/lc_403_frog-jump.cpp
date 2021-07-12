/**
 * 403. 青蛙过河
 * https://leetcode-cn.com/problems/frog-jump/
 */

class Solution {
public:
    // https://leetcode.com/problems/frog-jump/discuss/88810/C%2B%2B-9-lines-O(n2)-iterative-DP-solution
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        dp[0].insert(0);
        for (int pos : stones) {
            for (int step : dp[pos]) {
                if (step-1 > 0) dp[pos + step-1].insert(step-1);
                dp[pos + step].insert(step);
                dp[pos + step+1].insert(step+1);
            }
        }
        return !dp[stones.back()].empty();
    }
};
