class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        const int n = nums.size();

        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;

        for (int i = 1; i <= n; i++) {
            vector<int> seen(n, 0);
            int cost = 0;
            for (int j = i - 1; j >= 0; j--) {
                int x = nums[j];
                seen[x]++; cost++;
                if (seen[x] == 1) cost--;
                else if (seen[x] == 2) cost++;

                f[i] = min(f[i], f[j] + k + cost);
            }
        }

        return f[n];
    }
};
