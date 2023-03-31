class Solution {
public:
    // 贪心
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> b(banned.begin(), banned.end());

        int ans = 0;
        for (int i = 1; i <= n && maxSum >= i; i++) {
            if (b.find(i) != b.end())
                continue;

            maxSum -= i;
            ans++;
        }

        return ans;
    }
};
