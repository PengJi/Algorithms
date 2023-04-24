class Solution {
private:
    int ans;

    void solve(int i, int x, int y, const string &s) {
        if (i == s.size()) {
            ans = min(ans, x + y);

            return;
        }

        solve(i + 1, x * 10 + s[i] - '0', y, s);
        solve(i + 1, x, y * 10 + s[i] - '0', s);
    }

public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());

        ans = INT_MAX;
        solve(0, 0, 0, s);

        return ans;
    }
};
