#define LL long long

class Solution {
public:
    LL minCost(vector<int>& basket1, vector<int>& basket2) {
        const int n = basket1.size();
        unordered_map<int, int> seen, seen1;

        int mi = INT_MAX;
        for (int i = 0; i < n; i++) {
            ++seen[basket1[i]]; ++seen1[basket1[i]];
            ++seen[basket2[i]];

            mi = min(mi, basket1[i]);
            mi = min(mi, basket2[i]);
        }

        for (const auto &[_, v] : seen)
            if (v & 1)
                return -1;

        vector<int> ask, bid;

        for (const auto &[k, v]: seen) {
            if (seen1[k] < v / 2) {
                for (int i = 0; i < v / 2 - seen1[k]; i++)
                    ask.push_back(k);
            } else {
                for (int i = 0; i < seen1[k] - v / 2; i++)
                    bid.push_back(k);
            }
        }

        sort(ask.begin(), ask.end());
        sort(bid.begin(), bid.end());

        const int m = ask.size();
        LL ans = 0;

        for (int i = 0; i < m; i++)
            ans += min(2 * mi, min(ask[i], bid[m - i - 1]));

        return ans;
    }
};
