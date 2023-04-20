typedef long long LL;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        const int n = word.size();

        vector<int> ans(n);

        LL r = 0;
        for (int i = 0; i < n; i++) {
            r = (r * 10 + word[i] - '0') % m;

            if (r == 0) ans[i] = 1;
            else ans[i] = 0;
        }

        return ans;
    }
};
