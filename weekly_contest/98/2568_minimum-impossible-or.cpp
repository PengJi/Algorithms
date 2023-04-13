class Solution {
public:
    // 思维题
    int minImpossibleOR(vector<int>& nums) {
        int seen = 0;

        for (int x : nums)
            if ((x & (x - 1)) == 0)
                seen |= x;

        for (int i = 0; i < 30; i++)
            if (((seen >> i) & 1) == 0)
                return 1 << i;

        return 1 << 30;
    }
};
