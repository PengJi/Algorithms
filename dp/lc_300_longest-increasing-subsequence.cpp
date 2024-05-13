/**
 * 300. 最长上升子序列
 * https://leetcode.cn/problems/longest-increasing-subsequence
 */

class Solution {
public:
    // 状态表示：dp[i]记录以 nums[i] 结尾（即nums[i]为最后一个数字）的最长递增子序列的长度。
    // 初始状态：dp[0] = 1
    // 状态转移：dp[i]=max(dp[j]+1)，其中要求 1≤j<i 且 nums[j]<nums[i]。
    // 时间复杂度为 O(n^2)，对于每个 i，都需要从 1 遍历到 i。
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }

            if (dp[i] > res) res = dp[i];
        }

        return res;
    }
};

class Solution {
public:
    // 贪心 + 二分查找
    // 一个简单的贪心，如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，
    // 因此我们希望每次在上升子序列最后加上的那个数尽可能的小。
    // O(nlog⁡n)/O(n)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec;  // 表示以 i 为结尾的最长上升子序列

        for (auto& x : nums) {
            if (vec.empty() || x > vec.back())  // 边界情况：子序列为空或者当前元素大于子序列的最后一个元素
                vec.push_back(x);
            else if (x < vec.front())  // 边界情况：当前元素使子序列的最小值
                vec[0] = x;
            else {  // 当前元素位于子序列的中间
                // 二分法，查找当前元素 i 在子序列中的位置
                int l = 0, r = vec.size() - 1;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (vec[mid] < x)
                        l = mid + 1;
                    else
                        r = mid;
                }

                if (vec[l] != x) vec[l] = x;  // 未找到，修改子序列
            }
        }

        return vec.size();
    }
};
