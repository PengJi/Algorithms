const int M = 9, S = 19683;

class Solution {
private:
    int f[S], power[M + 1];

public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        const int n = nums.size();
        power[0] = 1;
        for (int i = 1; i <= numSlots; i++)
            power[i] = power[i - 1] * 3;

        for (int j = 0; j < power[numSlots]; j++)
            f[j] = 0;

        for (int i = 0; i < n; i++)
            for (int mask = power[numSlots] - 1; mask >= 0; mask--)
                for (int j = 0; j < numSlots; j++)
                    if (mask / power[j] % 3 > 0)
                        f[mask] = max(f[mask],
                            f[mask - power[j]] + (nums[i] & (j + 1)));

        int ans = 0;
        for (int mask = 0; mask < power[numSlots]; mask++)
            ans = max(ans, f[mask]);

        return ans;
    }
};
