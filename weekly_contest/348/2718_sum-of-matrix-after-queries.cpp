/**
 * 2718. 查询后矩阵的和
 * https://leetcode.cn/problems/sum-of-matrix-after-queries/description/
*/

#define LL long long

class Solution {
public:
    LL matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> r(n, false), c(n, false);
        int nr = n, nc = n;
        LL ans = 0;

        for (int i = queries.size() - 1; i >= 0; i--) {
            if (queries[i][0] == 0 && !r[queries[i][1]]) {
                ans += (LL)(queries[i][2]) * nc;
                r[queries[i][1]] = true;
                --nr;
            } else if (queries[i][0] == 1 && !c[queries[i][1]]) {
                ans += (LL)(queries[i][2]) * nr;
                c[queries[i][1]] = true;
                --nc;
            }
        }

        return ans;
    }
};
