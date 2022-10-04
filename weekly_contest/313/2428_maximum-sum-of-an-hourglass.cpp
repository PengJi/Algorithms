class Solution {
public:
    // 枚举沙漏的中心点
    int maxSum(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        int res = 0;
        for(int i = 1; i < m-1; i++) {
            for(int j = 1; j < n-1; j++) {
                int t = g[i][j];  // 中心点
                // 以列遍历
                for(int k = j-1; k <= j+1; k++) {
                    t += g[i-1][k] + g[i+1][k];  // 加上下两行
                }
                res = max(res, t);
            }
        }

        return res;
    }
};
