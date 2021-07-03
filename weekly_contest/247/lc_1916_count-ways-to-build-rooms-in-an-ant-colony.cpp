/**
 * 1916. 统计为蚁群构筑房间的不同顺序
 * https://leetcode-cn.com/problems/count-ways-to-build-rooms-in-an-ant-colony/
 */

typedef long long LL;

const int N = 100010, MOD = 1e9 + 7;

int f[N], g[N];
int s[N], sz[N];
int h[N], e[N], ne[N], idx;

class Solution {
public:
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
    }

    int dfs(int u) {
        sz[u] = 0;  // 初始时不包括根节点
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            dfs(j);
            sz[u] += sz[j];
        }
        s[u] = f[sz[u]];
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            s[u] = (LL)s[u] * g[sz[j]] % MOD * s[j] % MOD;
        }
        sz[u] ++ ;  // 加上根节点
        return s[u];
    }

    int qmi(int a, int k) {
        int res = 1;
        while (k) {
            if (k & 1) res = (LL)res * a % MOD;
            a = (LL)a * a % MOD;
            k >>= 1;
        }
        return res;
    }

    int waysToBuildRooms(vector<int>& p) {
        int n = p.size();
        memset(h, -1, sizeof h);
        idx = 0;

        f[0] = g[0] = 1;
        for (int i = 1; i <= n; i ++ ) {
            f[i] = (LL)f[i - 1] * i % MOD;
            g[i] = qmi(f[i], MOD - 2) % MOD;
        }

        for (int i = 1; i < n; i ++ ) add(p[i], i);
        return dfs(0);
    }
};
