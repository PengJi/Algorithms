/**
 * 2791. 树中可以形成回文的路径数
 * https://leetcode.cn/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/
*/
#define LL long long

const int N = 100010, H = 99997;

struct Edge {
    int to, w, nxt;
};

struct HashNode {
    int k, v, nxt;
};

class HashMap {
    HashNode h[N];
    int cnt, head[H];

public:
    HashMap() {
        cnt = 0;
        memset(head, -1, sizeof(head));
    }

    void insert(int x) {
        for (int i = head[x % H]; ~i; i = h[i].nxt)
            if (h[i].k == x) {
                ++h[i].v;

                return;
            }

        h[cnt].k = x;
        h[cnt].v = 1;
        h[cnt].nxt = head[x % H];
        head[x % H] = cnt++;
    }

    int count(int x) {
        for (int i = head[x % H]; ~i; i = h[i].nxt)
            if (h[i].k == x)
                return h[i].v;

        return 0;
    }

    void clear(int x) {
        head[x % H] = -1;
    }

    void reset_cnt() {
        cnt = 0;
    }
};

class Solution {
private:
    Edge e[2 * N];
    int head[N], cnt;

    bool vis[N];
    int sz[N], mx[N];
    LL ans;

    int d[N];
    HashMap mp;

    // 建图
    void add(int x, int y, int z) {
        e[cnt].to = y;
        e[cnt].w = z;
        e[cnt].nxt = head[x];
        head[x] = cnt++;
    }

    // 求树的重心
    void get_cent(int u, int fa, int whole, int &cent, int &mw) {
        sz[u] = 1;
        mx[u] = 0;

        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;

            if (v == fa || vis[v])
                continue;

            get_cent(v, u, whole, cent, mw);
            sz[u] += sz[v];
            mx[u] = max(mx[u], sz[v]);
        }

        mx[u] = max(mx[u], whole - sz[u]);

        if (mx[u] < mw) {
            cent = u;
            mw = mx[u];
        }
    }

    // 求每个点到根节点的路径值
    void get_dis(int u, int fa, int now, int &counter) {
        d[counter++] = now;

        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (v == fa || vis[v])
                continue;

            get_dis(v, u, now ^ (1 << e[i].w), counter);
        }
    }

    // 哈希表统计当前根节点贡献的答案。
    void calc(int u) {
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (vis[v])
                continue;

            int counter = 0;
            get_dis(v, u, 1 << e[i].w, counter);

            for (int j = 0; j < counter; j++) {
                int s = d[j];
                if (s == 0)
                    ++ans;

                ans += mp.count(s);

                for (int k = 0; k < 26; k++) {
                    if (s == (1 << k))
                        ++ans;

                    ans += mp.count(s ^ (1 << k));
                }
            }

            for (int j = 0; j < counter; j++)
                mp.insert(d[j]);
        }

        // 这里不能直接暴力清空哈希表，需要把插入的元素一一清除
        int counter = 0;
        get_dis(u, -1, 0, counter);
        for (int j = 1; j < counter; j++)
            mp.clear(d[j]);
        mp.reset_cnt();
    }

    // 递归分治
    void solve(int x, int whole) {
        int u = -1, mw = INT_MAX;
        get_cent(x, -1, whole, u, mw);
        calc(u);

        vis[u] = true;

        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (vis[v])
                continue;

            if (sz[v] < sz[u]) solve(v, sz[v]);
            else solve(v, whole - sz[u]);
        }
    }

public:
    LL countPalindromePaths(vector<int>& parent, string s) {
        const int n = parent.size();

        cnt = 0;
        for (int i = 0; i < n; i++) {
            head[i] = -1;
            vis[i] = false;
        }

        for (int i = 1; i < n; i++) {
            add(parent[i], i, s[i] - 'a');
            add(i, parent[i], s[i] - 'a');
        }

        ans = 0;
        solve(0, n);

        return ans;
    }
};
