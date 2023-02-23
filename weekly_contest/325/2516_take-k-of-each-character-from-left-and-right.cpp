/**
 * 2516. 每种字符至少取 K 个
 * https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right/
*/

class Solution {
private:
    bool check(int p, const vector<int> &pre, const vector<vector<int>> &suf, int k) {
        for (int i = 0; i < 3; i++)
            if (pre[i] + suf[p][i] < k)
                return false;

        return true;
    }

public:
    int takeCharacters(string s, int k) {
        const int n = s.size();

        vector<vector<int>> suf(n + 1, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            suf[i][s[i] - 'a']++;
        }

        int ans = n + 1;

        vector<int> pre(3, 0);

        for (int i = 0; i <= n; i++) {
            int l = i - 1, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (check(mid + 1, pre, suf, k))
                    l = mid + 1;
                else
                    r = mid;
            }

            if (l != i - 1)
                ans = min(ans, i + n - l);

            if (i < n)
                pre[s[i] - 'a']++;
        }

        if (ans == n + 1)
            ans = -1;

        return ans;
    }
};
