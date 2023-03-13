#define LL long long

class Solution {
public:
    LL minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n = nums1.size();

        LL sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += nums1[i];
            sum2 += nums2[i];
        }

        if (sum1 != sum2)
            return -1;

        LL res = 0;

        for (int i = 0; i < n; i++) {
            if (nums1[i] == nums2[i])
                continue;

            if (k == 0 || (nums1[i] - nums2[i]) % k != 0)
                return -1;

            res += abs(nums1[i] - nums2[i]) / k;
        }

        return res / 2;
    }
};
