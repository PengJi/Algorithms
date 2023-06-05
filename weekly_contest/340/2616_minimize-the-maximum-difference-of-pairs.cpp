/**
 * 2616. 最小化数对的最大差值
 * https://leetcode.cn/problems/minimize-the-maximum-difference-of-pairs/
*/
class Solution {
public:
    bool check(int m, const vector<int> &nums, int p) {
        const int n = nums.size();

        for (int i = 0; i < n - 1 && p; i++) {
            if (nums[i + 1] - nums[i] > m)
                continue;

            p--;
            i++;
        }

        return p <= 0;
    }

    // 二分、贪心
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.back() - nums[0];
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid, nums, p)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
