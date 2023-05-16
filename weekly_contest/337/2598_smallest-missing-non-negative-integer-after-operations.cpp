class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> r(value, 0);

        for (int x : nums)
            ++r[(x % value + value) % value];

        int mi = INT_MAX;
        for (int i = 0; i < value; i++)
            if (mi > r[i])
                mi = r[i];

        for (int i = 0; i < value; i++)
            if (mi == r[i])
                return mi * value + i;

        return -1;
    }
};
