/**
 * 2733. 既不是最小值也不是最大值
 * https://leetcode.cn/problems/neither-minimum-nor-maximum/description/
*/

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int ma = 0, mi = 101;
        for (int x : nums) {
            if (ma < x) ma = x;
            if (mi > x) mi = x;
        }

        for (int x : nums)
            if (x != ma && x != mi)
                return x;

        return -1;
    }
};
