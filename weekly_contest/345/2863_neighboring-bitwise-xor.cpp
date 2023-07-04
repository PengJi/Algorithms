/**
 * 2683. 相邻值的按位异或
 * https://leetcode.cn/problems/neighboring-bitwise-xor/
*/
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        const int n = derived.size();

        int c = 0;

        for (int i = 0; i < n - 1; i++)
            c ^= derived[i];

        return c == derived[n - 1];
    }
};
