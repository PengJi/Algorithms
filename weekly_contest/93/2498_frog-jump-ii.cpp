class Solution {
public:
    // 贪心
    int maxJump(vector<int>& stones) {
        const int n = stones.size();
        if (n == 2)
            return stones[1] - stones[0];

        int ans = 0;
        for (int i = 2; i < n; i++)
            ans = max(ans, stones[i] - stones[i - 2]);

        return ans;
    }
};
