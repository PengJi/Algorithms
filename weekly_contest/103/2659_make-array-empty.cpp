/**
 * 2659. 将数组清空
 * https://leetcode.cn/problems/make-array-empty/
*/
typedef long long LL;

class Solution {
public:
    LL countOperationsToEmptyArray(vector<int>& nums) {
        const int n = nums.size();

        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int x, int y) {
            return nums[x] < nums[y];
        });

        LL ans = n;
        for (int i = 1; i < n; i++)
            if (id[i] < id[i - 1])
                ans += n - i;

        return ans;
    }
};
