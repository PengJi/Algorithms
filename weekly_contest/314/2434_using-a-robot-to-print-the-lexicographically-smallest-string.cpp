class Solution {
public:
    // 贪心
    string robotWithString(string s) {
        const int n = s.size();

        vector<char> mi(n);

        mi[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--)
            mi[i] = min(mi[i + 1], s[i]);

        string t, ans;
        for (int i = 0; i < n; i++) {
            while (!t.empty() && t.back() <= mi[i]) {
                ans += t.back();
                t.pop_back();
            }

            t += s[i];
        }

        while (!t.empty()) {
            ans += t.back();
            t.pop_back();
        }

        return ans;
    }
};
