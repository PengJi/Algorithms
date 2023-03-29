#define LL long long

class Solution {
public:
    LL countQuadruplets(vector<int>& nums) {
        const int n = nums.size();

        vector<int> less(n + 1, 0);
        vector<vector<int>> greater(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            greater[i] = greater[i + 1];
            for (int p = 1; p < nums[i]; p++)
                ++greater[i][p];
        }

        LL ans = 0;

        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++)
                if (nums[k] < nums[j])
                    ans += (LL)(less[nums[k]]) * greater[k + 1][nums[j]];

            for (int p = nums[j] + 1; p <= n; p++)
                ++less[p];
        }

        return ans;
    }
};
