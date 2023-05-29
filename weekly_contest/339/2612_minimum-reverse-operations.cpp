class Solution {
public:
    // 宽度优先遍历
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<bool> banned_map(n, false);
        for (int x : banned)
            banned_map[x] = true;

        set<int> s[2];
        for (int i = 0; i < n; i++) {
            if (banned_map[i] || i == p)
                continue;

            s[i & 1].insert(i);
        }

        vector<int> d(n, -1);
        d[p] = 0;

        queue<int> q;
        q.push(p);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            int l = max(-k + 1, k - 1 - 2 * u);
            int r = min(k - 1, -k - 2 * u + 2 * n - 1);

            set<int> &t = s[((u ^ k) & 1) ^ 1];
            auto it = t.lower_bound(u + l);
            vector<int> tbd;
            while (it != t.end() && *it <= u + r) {
                tbd.push_back(*it);
                d[*it] = d[u] + 1;
                q.push(*it);
                ++it;
            }

            for (int v : tbd)
                t.erase(v);
        }

        return d;
    }
};
