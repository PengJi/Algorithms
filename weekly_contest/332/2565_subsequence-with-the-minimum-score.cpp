class Solution {
public:
    // 思维题
    int minimumScore(string s, string t) {
        const int n = s.size(), m = t.size();

        vector<int> p(n);

        for (int i = 0, j = 0; i < n; i++) {
            if (j < m && s[i] == t[j])
                j++;

            p[i] = j;
        }

        int ans = m - p[n - 1];

        for (int i = m - 1, j = n - 1; i >= 0; i--) {
            while (j >= 0 && t[i] != s[j])
                j--;

            if (j < 0)
                break;

            if (j == 0) ans = min(ans, i);
            else ans = min(ans, max(0, i - p[j - 1]));

            j--;
        }

        return ans;
    }
};
