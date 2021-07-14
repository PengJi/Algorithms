/**
 * 539. 最小时间差
 * https://leetcode-cn.com/problems/minimum-time-difference/
 */

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;
        vector<int> q;
        for(string t : timePoints) {
            int m, n;
            sscanf(t.c_str(), "%d:%d", &m, &n);
            q.push_back(m * 60 + n);
        }
        sort(q.begin(), q.end());
        for(int i = 1; i < q.size(); i++) {
            res = min(res, q[i] - q[i-1]);
        }
        res = min(res, 24*60 - q.back() + q[0]);

        return res;
    }
};
