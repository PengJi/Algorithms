class Solution {
public:
    int n;

    bool check(int m, const vector<int> &nums, int k) {
        bool prev = false;
        int tot = 0;

        for (int i = 0; i < n && tot < k; i++) {
            if (nums[i] <= m && !prev) {
                tot++;
                prev = true;
            } else {
                prev = false;
            }
        }

        return tot >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        n = nums.size();

        int l = 1, r = 1000000000;

        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid, nums, k)) r = mid;
            else l = mid + 1; 
        }

        return l;
    }
};
