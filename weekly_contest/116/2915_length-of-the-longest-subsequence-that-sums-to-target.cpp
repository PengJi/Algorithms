/**
 * 2915. 和为目标值的最长子序列的长度
 * https://leetcode.cn/problems/length-of-the-longest-subsequence-that-sums-to-target/description/
*/
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        const int n = nums.size();

        vector<int> f(target + 1, INT_MIN);
        f[0] = 0;

        for (int x : nums)
            for (int j = target; j >= x; j--)
                f[j] = max(f[j], f[j - x] + 1);

        return f[target] < 0 ? -1 : f[target];
    }
};

作者：wzc1995
链接：https://www.acwing.com/solution/content/211718/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。