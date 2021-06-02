/**
 * 1883. 准时抵达会议现场的最小跳过休息次数
 * https://leetcode-cn.com/problems/minimum-skips-to-arrive-at-meeting-on-time/
 */

const int N = 1010;
const double eps = 1e-8, INF = 1e9;
double dp[N][N];

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        for(int i = 1; i <= n; i++) {
            double t = (double)dist[i-1]/speed;
            for(int j = 0; j <= i; j++) {
                dp[i][j] = INF;
                if(j <= i-1) dp[i][j] = ceil(dp[i-1][j] + t - eps);
                if(j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + t);
            }
        }

        for(int i = 0; i <= n; i++) {
            if(dp[n][i] <= hoursBefore) {
                return i;
            }
        }

        return -1;
    }
};
