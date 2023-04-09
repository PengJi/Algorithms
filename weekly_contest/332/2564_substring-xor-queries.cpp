typedef long logn LL;

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        const int n = s.size();

        unordered_map<LL, vector<int>> h;

        for (int len = 1; len <= 30 && len <= n; len++) {
            LL x = 0;
            for (int i = 0; i < len - 1; i++)
                x = (x << 1) | (s[i] - '0');

            for (int i = len - 1; i < n; i++) {
                x = (x << 1) | (s[i] - '0');

                if (h.find(x) == h.end())
                    h[x] = {i - len + 1, i};

                x ^= (s[i - len + 1] - '0') << (len - 1);
            }
        }

        vector<vector<int>> ans;
        for (const auto &q : queries) {
            LL x = q[0] ^ q[1];

            if (h.find(x) == h.end()) ans.push_back({-1, -1});
            else ans.push_back(h[x]);
        }

        return ans;
    }
};
