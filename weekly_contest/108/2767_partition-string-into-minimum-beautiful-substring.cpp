/**
 * 2767. 将字符串分割为最少的美丽子字符串
 * https://leetcode.cn/problems/partition-string-into-minimum-beautiful-substrings/description/
*/

class Solution {
private:
    int ans;

    bool check(int x) {
        return x == 1 || x == 5 || x == 25 || x == 125 || 
            x == 625 || x == 3125 || x == 15625;
    }

    void solve(int i, int x, int cnt, const string &s) {
        if (x == 0)
            return;

        if (i == s.size()) {
            if (check(x))
                ans = min(ans, cnt);

            return;
        }

        solve(i + 1, (x << 1) | (s[i] - '0'), cnt, s);

        if (check(x))
            solve(i + 1, s[i] - '0', cnt + 1, s);
    }

public:
    // 递归回溯
    int minimumBeautifulSubstrings(string s) {
        ans = INT_MAX;

        solve(1, s[0] - '0', 1, s);

        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};
