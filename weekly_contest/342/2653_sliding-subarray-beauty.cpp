/**
 * 2653. 滑动子数组的美丽值
 * https://leetcode.cn/problems/sliding-subarray-beauty/
*/
const int N = 101;

class Solution {
public:
    // 滑动窗口
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        const int n = nums.size();

        int v[N];
        memset(v, 0, sizeof(v));

        for (int i = 0; i < k - 1; i++)
            ++v[nums[i] + 50];

        vector<int> ans;
        for (int i = k - 1; i < n; i++) {
            ++v[nums[i] + 50];

            int t = x, r = 0;
            for (int j = 0; j < 50; j++) {
                t -= v[j];
                if (t <= 0) {
                    r = j - 50;

                    break;
                }
            }

            ans.push_back(r);

            --v[nums[i - k + 1] + 50];
        }

        return ans;
    }
};
