class Solution {
public:
    // 双指针
    int maximizeWin(vector<int>& prizePositions, int k) {
        const int n = prizePositions.size();

        if (prizePositions[n - 1] - prizePositions[0] <= 2 * k)
            return n;

        vector<int> r(n + 1);
        r[n] = 0;
        for (int i = n - 1, j = n - 1; i >= 0; i--) {
            while (prizePositions[j] - prizePositions[i] > k)
                j--;

            r[i] = max(r[i + 1], j - i + 1);
        }

        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (prizePositions[i] - prizePositions[j] > k)
                j++;

            ans = max(ans, i - j + 1 + r[i + 1]);
        }

        return ans;
    }
};
