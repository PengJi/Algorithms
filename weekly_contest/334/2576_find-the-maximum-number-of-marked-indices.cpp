class Solution {
private:
    bool check(int p, const vector<int> &nums, int n) {
        for (int i = 0; i < p; i++)
            if (2 * nums[i] > nums[n - p + i])
                return false;

        return true;
    }

public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        const int n = nums.size();

        int l = 0, r = n / 2;

        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid + 1, nums, n)) l = mid + 1;
            else r = mid;
        }

        return 2 * l;
    }
};
