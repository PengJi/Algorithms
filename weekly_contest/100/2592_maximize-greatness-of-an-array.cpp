class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && nums[j] <= nums[i])
                j++;

            if (j == n)
                break;

            ans++;
            j++;
        }

        return ans;
    }
};
