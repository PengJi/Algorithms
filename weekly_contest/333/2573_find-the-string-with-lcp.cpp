class Solution {
public:
    // 动态规划
    string findTheString(vector<vector<int>>& lcp) {
        const int n = lcp.size();

        string r(n, ' ');
        int c = 0;

        for (int i = 0; i < n; i++) {
            if (r[i] != ' ')
                continue;

            if (c == 26)
                return "";

            r[i] = c + 'a';
            c++;
            for (int j = i + 1; j < n; j++)
                if (lcp[i][j] > 0)
                    r[j] = r[i];
        }

        for (int i = n - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--) {
                if (r[i] != r[j]) {
                    if (lcp[i][j] != 0)
                        return "";
                } else {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1)
                            return "";
                    } else {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1)
                            return "";
                    }
                }
            }

        return r;
    }
};
