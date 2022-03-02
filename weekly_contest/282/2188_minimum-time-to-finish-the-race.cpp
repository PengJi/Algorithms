class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        vector<int> best(18, INT_MAX);
        // 记录真正的最大连续使用的圈数，17 只是我们估计出的上界
        int maxdiff = 0;
        for (const auto& tire: tires) {
            long long lap = tire[0], cur = tire[0];
            for (int i = 1; lap < changeTime + tire[0]; ++i) {
                best[i] = min(best[i], static_cast<int>(cur));
                lap *= tire[1];
                cur += lap;
                maxdiff = max(maxdiff, i);
            }
        }
        
        vector<int> f(numLaps + 1, INT_MAX);
        f[0] = 0;
        for (int i = 1; i <= numLaps; ++i) {
            for (int j = i - 1; j >= 0 && i - j <= maxdiff; --j) {
                f[i] = min(f[i], f[j] + best[i - j] + changeTime);
            }
        }
        return f[numLaps] - changeTime;
    }
};
