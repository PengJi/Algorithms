/**
 * 5983. 同时运行 N 台电脑的最长时间
 * https://leetcode-cn.com/problems/maximum-running-time-of-n-computers/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/maximum-running-time-of-n-computers/solution/er-fen-da-an-by-newhar-swi2/
    long long maxRunTime(int n, vector<int>& batteries) {
        auto check = [&](long long t) {
            long long sum = 0;
            for(int i : batteries) sum += min(t, (long long)i);
            return sum / t >= n;
        };
        
        long long l = 1, r = 1e16;
        while(l < r) {
            long long m = (l + r) / 2;
            if(check(m)) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l - 1;
    }
};
