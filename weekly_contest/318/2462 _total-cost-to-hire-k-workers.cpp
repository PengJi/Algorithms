#define LL long long

class Solution {
public:
    // 使用堆
    // 使用小根堆存储当前在 candidates 中的工人。
    // 每次取出一位工人，判断其在前部分还是后部分，然后再加入对应部分的一位工人。
    LL totalCost(vector<int>& costs, int k, int candidates) {
        const int n = costs.size();
        priority_queue<pair<int, int>> heap;

        LL ans = 0;
        int l = 0, r = 0;
        while (l + r < n && l < candidates) {
            heap.push(make_pair(-costs[l], -l));
            l++;
        }

        while (l + r < n && r < candidates) {
            heap.push(make_pair(-costs[n - r - 1], -(n - r - 1)));
            r++;
        }

        while (k--) {
            auto t = heap.top();
            heap.pop();

            int cost = -t.first, idx = -t.second;

            ans += cost;

            if (l + r == n)
                continue;

            if (idx < l) {
                heap.push(make_pair(-costs[l], -l));
                l++;
            } else {
                heap.push(make_pair(-costs[n - r - 1], -(n - r - 1)));
                r++;
            }
        }

        return ans;
    }
};
