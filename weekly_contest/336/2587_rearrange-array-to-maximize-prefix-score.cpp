typedef long long LL;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) {
            return x > y;
        });

        const int n = nums.size();

        LL s = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];
            if (s <= 0)
                return i;
        }

        return n;
    }
};
