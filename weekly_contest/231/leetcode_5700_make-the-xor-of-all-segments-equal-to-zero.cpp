/**
 * 5700. 使所有区间的异或结果为零
 * https://leetcode-cn.com/problems/make-the-xor-of-all-segments-equal-to-zero/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/make-the-xor-of-all-segments-equal-to-zero/solution/an-yu-shu-fen-zu-jin-xing-dong-tai-gui-h-7z0g/
    int minChanges(vector<int>& nums, int k) {
        const int INF = 0x3f3f3f3f;

        int n = nums.size();
        vector<unordered_map<int, int>> groups(k);
        vector<int> size(k);
        for (int i = 0; i < k; ++i) {
            for (int j = i; j < n; j += k) {
                groups[i][nums[j]]++;
                size[i]++;
            }
        }
        
        vector<int> dp(1 << 10, INF);
        dp[0] = 0;
        for (int i = 0; i < k; ++i) {
            int lo = *min_element(dp.begin(), dp.end());
            vector<int> ndp(1 << 10, lo + size[i]);
            for (int j = 0; j < (1 << 10); ++j) {
                if (dp[j] == INF)
                    continue;
                for (auto [p, freq] : groups[i]) {
                    int nxt = p ^ j;
                    ndp[nxt] = min(ndp[nxt], dp[j] + size[i] - freq);
                }
            }
            dp = move(ndp);
        }
        
        return dp[0];
    }
};
