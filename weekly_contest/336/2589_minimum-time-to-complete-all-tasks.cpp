class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        const int M = 2010;

        const int n = tasks.size();

        sort(tasks.begin(), tasks.end(),
            [](const vector<int> &x, const vector<int> &y) {
                return x[1] < y[1];
            }
        );

        vector<bool> v(M, false);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = tasks[i][0]; j <= tasks[i][1] && tasks[i][2] > 0; j++)
                if (v[j])
                    tasks[i][2]--;

            if (tasks[i][2] == 0)
                continue;

            for (int j = tasks[i][1]; tasks[i][2] > 0; j--)
                if (!v[j]) {
                    ans++;
                    v[j] = true;
                    tasks[i][2]--;
                }
        }

        return ans;
    }
};
