class Solution {
public:
    // 模拟
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int res = logs[0][0];
        int max = logs[0][1];

        for(int i = 1; i < logs.size(); i++) {
            int cur = logs[i][1] - logs[i-1][1];
            if(cur > max) {
                res = logs[i][0];
                max = cur;
            } else if (cur == max) {
                if(res > logs[i][0]) res = logs[i][0];
            }
        }

        return res;
    }
};
