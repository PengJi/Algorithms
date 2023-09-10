/**
 * 2768. 黑格子的数目
 * https://leetcode.cn/problems/number-of-black-blocks/description/
*/

#define LL long long

const int dx[] = {-1, -1, 0, 0};
const int dy[] = {-1, 0, -1, 0};

class Solution {
public:
    vector<LL> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<LL, int> seen;

        for (const auto &c : coordinates) {
            int x = c[0], y = c[1];

            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i], ty = y + dy[i];

                if (tx < 0 || tx >= m - 1 || ty < 0 || ty >= n - 1)
                    continue;

                ++seen[(LL)(tx) * n + ty];
            }
        }

        vector<LL> ans(5, 0);

        for (const auto &[_, v] : seen)
            ++ans[v];

        ans[0] = (LL)(m - 1) * (n - 1) - ans[1] - ans[2] - ans[3] - ans[4];

        return ans;
    }
};
