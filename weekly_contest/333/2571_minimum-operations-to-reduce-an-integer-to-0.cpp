class Solution {
public:
    // 贪心
    int minOperations(int n) {
        int ans = 0;

        while (n) {
            if ((n & 1) == 0) {
                n >>= 1;
            } else if ((n & 3) == 3) {
                n++;
                ans++;
            } else {
                n >>= 1;
                ans++;
            }
        }

        return ans;
    }
};
