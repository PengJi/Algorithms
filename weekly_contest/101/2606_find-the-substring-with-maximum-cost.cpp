class Solution {
public:
    // 动态规划
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> v(26);
        for (int i = 0; i < 26; i++)
            v[i] = i + 1;

        for (int i = 0; i < chars.size(); i++)
            v[chars[i] - 'a'] = vals[i];

        int f = 0, ans = 0;
        for (char c : s) {
            // 状态转移
            if (f < 0) f = v[c - 'a'];
            else f += v[c - 'a'];

            ans = max(ans, f);
        }

        return ans;
    }
};
