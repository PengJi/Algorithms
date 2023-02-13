#define LL long long

class Solution {
public:
    LL minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        LL ans = 0;

        int tot = 0;
        unordered_map<int, int> h;

        for (int i = 0; i < n; i++) {
            if (nums1[i] != nums2[i])
                continue;

            h[nums1[i]]++;
            tot++;
            ans += i;
            nums1[i] = -1;
        }

        int x = -1, c;
        for (const auto &[k, v] : h)
            if (v * 2 > tot) {
                x = k;
                c = v;

                break;
            }

        if (x == -1)
            return ans;

        c -= tot - c;
        for (int i = 0; i < n && c > 0; i++)
            if (nums1[i] != -1 && nums1[i] != x && nums2[i] != x) {
                ans += i;
                c--;
            }

        if (c > 0)
            return -1;

        return ans;
    }
};
