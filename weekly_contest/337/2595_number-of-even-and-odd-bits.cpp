class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2, 0);

        int b = 0;
        while (n) {
            if (n & 1)
                ++ans[b];

            b ^= 1;
            n >>= 1;
        }

        return ans;
    }
};
