class Solution {
public:
    // 思维题
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());

        // 寻找同时存在的数字
        int ans = 10;
        for (int x : nums2)
            if (s1.find(x) != s1.end())
                ans = min(ans, x);

        if (ans < 10)
            return ans;

        // 否则分别找最小的数字
        int m1 = 10, m2 = 10;
        for (int x : nums1)
            m1 = min(m1, x);

        for (int x : nums2)
            m2 = min(m2, x);

        return min(m1, m2) * 10 + max(m1, m2);
    }
};
