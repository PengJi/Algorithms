/**
 * 149. 直线上最多的点数
 * https://leetcode-cn.com/problems/max-points-on-a-line/
 */

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/405120/
    int maxPoints(vector<vector<int>>& points) {
        typedef long double LD;

        int res = 0;
        for(auto& p : points) {
            int ss = 0, vs = 0;  // 与起始点在同一个位置、垂直直线上的点
            unordered_map<LD, int> cnt;
            for(auto& q : points) {
                if(p == q) ss++;
                else if( p[0] == q[0]) vs++;
                else {
                    LD k = (LD) (q[1] - p[1]) / (q[0] - p[0]);
                    cnt[k]++;
                }
            }
            int c = vs;
            for(auto [k, t] : cnt) c = max(c, t);
            res = max(res, c + ss);
        }

        return res;
    }
};
