/**
 * 2747. 统计没有收到请求的服务器数目
 * https://leetcode.cn/problems/count-zero-request-servers/description/
*/

class Solution {
public:
    // 滑动窗口
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
        vector<int>& queries
    ) {
        const int q = queries.size();

        vector<int> qid(q);
        iota(qid.begin(), qid.end(), 0);

        sort(qid.begin(), qid.end(), [&](int x, int y) {
            return queries[x] < queries[y];
        });

        sort(logs.begin(), logs.end(), [](const vector<int> &x, const vector<int> &y) {
            return x[1] < y[1];
        });

        vector<int> seen(n, 0);
        int cnt = n;

        vector<int> ans(q);
        for (int i = 0, h = 0, t = 0; i < q; i++) {
            while (t < logs.size() && logs[t][1] <= queries[qid[i]]) {
                ++seen[logs[t][0] - 1];
                if (seen[logs[t][0] - 1] == 1)
                    --cnt;

                ++t;
            }

            while (h < t && logs[h][1] < queries[qid[i]] - x) {
                --seen[logs[h][0] - 1];
                if (seen[logs[h][0] - 1] == 0)
                    ++cnt;

                ++h;
            }

            ans[qid[i]] = cnt;
        }

        return ans;
    }
};
