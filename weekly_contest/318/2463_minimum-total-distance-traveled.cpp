#define LL long long

const int N = 110;
const LL INF = 100000000000000ll;

class Solution {
private:
    LL f[N][N];

public:
    LL minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        const int n = robot.size(), m = factory.size();

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        for (int i = 0; i <= m; i++) {
            f[i][0] = 0;
            for (int j = 1; j <= n; j++)
                f[i][j] = INF;
        }

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                f[i][j] = f[i - 1][j];

                LL sum = 0;
                for (int k = j; k > max(0, j - factory[i - 1][1]); k--) {
                    sum += abs(robot[k - 1] - factory[i - 1][0]);
                    f[i][j] = min(f[i][j], f[i - 1][k - 1] + sum);
                }
            }

        return f[m][n];
    }
};
