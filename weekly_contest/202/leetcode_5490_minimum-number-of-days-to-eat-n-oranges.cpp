/**
 * 5490. 吃掉 N 个橘子的最少天数
 * https://leetcode-cn.com/problems/minimum-number-of-days-to-eat-n-oranges/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/minimum-number-of-days-to-eat-n-oranges/solution/tan-xin-yi-xia-by-time-limit/
    unordered_map<int, int> m;
    int minDays(int n) {
        return dfs(n);
    }

    int dfs(int n) {
        if(n <= 1) return n;

        auto it = m.find(n);
        if(it != m.end()) {
            return it->second;
        }

        return m[n] = min(dfs(n/2) + n % 2, dfs(n/3) + n % 3) + 1;
    }
};
