/**
 * 2931. 购买物品的最大开销
 * https://leetcode.cn/problems/maximum-spending-after-buying-items/description/
*/
#define LL long long

struct T {
    int v, x, y;
    T(int v_, int x_, int y_):v(v_), x(x_), y(y_){}
    bool operator < (const T &p) const {
        return v > p.v;
    }
};

class Solution {
public:
    LL maxSpending(vector<vector<int>>& values) {
        const int m = values.size();
        const int n = values[0].size();

        priority_queue<T> heap;
        for (int i = 0; i < m; i++)
            heap.push(T(values[i][n - 1], i, n - 1));

        LL ans = 0;
        for (int d = 1; d <= m * n; d++) {
            T t = heap.top();
            heap.pop();

            ans += (LL)(t.v) * d;
            if (t.y > 0)
                heap.push(T(values[t.x][t.y - 1], t.x, t.y - 1));
        }

        return ans;
    }
};
