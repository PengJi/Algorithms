/**
 * 2811. 判断是否能拆分数组
 * https://leetcode.cn/problems/check-if-it-is-possible-to-split-array/description/
*/
const int N = 110;

class Solution {
private:
    bool f[N][N];
    int sum[N];

public:
    bool canSplitArray(vector<int>& nums, int m) {
        const int n = nums.size();

        sum[0] = 0;
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + nums[i - 1];

        for (int i = 1; i <= n; i++)
            f[i][i] = true;

        for (int i = n; i >= 1; i--)
            for (int j = i + 1; j <= n; j++) {
                f[i][j] = false;

                for (int k = i; k < j; k++) {
                    if (!f[i][k] || !f[k + 1][j])
                        continue;

                    if (k > i && sum[k] - sum[i - 1] < m)
                        continue;

                    if (k < j - 1 && sum[j] - sum[k] < m)
                        continue;

                    f[i][j] = true;

                    break;
                }
            }

        return f[1][n];
    }
};
