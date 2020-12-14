/**
 * 1688. 比赛中的配对次数
 * https://leetcode-cn.com/problems/count-of-matches-in-tournament/
 */

class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while(n > 1) {
            ans += n/2;
            if(n % 2 == 0) {
                n = n/2;
            } else {
                n = n/2 + 1;
            }
        }
        
        return ans;
    }
};
