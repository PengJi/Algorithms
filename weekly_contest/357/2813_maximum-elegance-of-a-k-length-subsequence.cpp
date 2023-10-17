/**
 * 2813. 子序列最大优雅度
 * https://leetcode.cn/problems/maximum-elegance-of-a-k-length-subsequence/description/
*/
#define LL long long

class Solution {
public:
    LL findMaximumElegance(vector<vector<int>>& items, int k) {
        const int n = items.size();

        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int x, int y) {
            return items[x][0] > items[y][0];
        });

        vector<bool> seen(n + 1, false);

        LL tot = 0, kind = 0;
        vector<int> dup;

        for (int i = 0; i < k; i++) {
            tot += items[id[i]][0];

            if (!seen[items[id[i]][1]]) {
                ++kind;
                seen[items[id[i]][1]] = true;
            } else {
                dup.push_back(id[i]);
            }
        }

        const int m = dup.size();

        LL ans = tot + kind * kind;
        for (int i = m - 1, j = k; i >= 0; i--) {
            ++kind;
            if (kind > k)
                break;

            tot -= items[dup[i]][0];

            while (j < n && seen[items[id[j]][1]])
                ++j;

            if (j == n)
                break;

            seen[items[id[j]][1]] = true;
            tot += items[id[j]][0];

            ans = max(ans, tot + kind * kind);
        }

        return ans;
    }
};
