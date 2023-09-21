/**
 * 2779. 数组的最大美丽值
 * https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/description/
*/

const int N = 300010;

class Solution {
private:
    int v[N];

public:
    // 差分
    int maximumBeauty(vector<int>& nums, int k) {
        memset(v, 0, sizeof(v));

        for (int x : nums) {
            ++v[x];
            --v[x + 2 * k + 1];
        }

        int ans = 0, p = 0;
        for (int i = 0; i < N; i++) {
            p += v[i];
            ans = max(ans, p);
        }

        return ans;
    }
};
