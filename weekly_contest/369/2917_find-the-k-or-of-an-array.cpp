/**
 * 2917. 找出数组中的 K-or 值
 * https://leetcode.cn/problems/find-the-k-or-of-an-array/description/
*/
class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            int cnt = 0;
            for (int x : nums)
                if ((x >> i) & 1)
                    ++cnt;

            if (cnt >= k)
                ans |= 1 << i;
        }

        return ans;
    }
};
