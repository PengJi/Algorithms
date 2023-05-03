const int N = 80000, M = 1000010;

class Solution {
private:
    int p[N], cnt, idx[M];
    bool vis[M];

public:
    int findValidSplit(vector<int>& nums) {
        const int n = nums.size();

        memset(vis, 0, sizeof(vis));
        cnt = 0;
        for (int i = 2; i < M; i++) {
            if (!vis[i]) {
                idx[i] = cnt;
                p[cnt] = i;
                cnt++;
            }

            for (int j = 0; j < cnt && i * p[j] < M; j++) {
                vis[i * p[j]] = true;
                if (i % p[j] == 0)
                    break;
            }
        }

        vector<bitset<N>> s(n), pre(n), suf(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = 0; j < cnt && p[j] * p[j] <= x; j++) {
                if (x % p[j] == 0)
                    s[i].set(j);

                while (x % p[j] == 0)
                    x /= p[j];
            }

            if (x > 1)
                s[i].set(idx[x]);
        }

        pre[0] = s[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] | s[i];

        suf[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] | s[i];

        for (int i = 0; i < n - 1; i++)
            if ((pre[i] & suf[i + 1]).none())
                return i;

        return -1;
    }
};
