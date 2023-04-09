typedef long long LL;

class Solution {
public:
    // 双指针
    LL findTheArrayConcVal(vector<int>& nums) {
        const int n = nums.size();
        LL ans = 0;

        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (i == j) {
                ans += nums[i];

                continue;
            }

            int x = nums[i], y = nums[j];
            ans += y;
            while (y) {
                x *= 10;
                y /= 10;
            }
            ans += x;
        }

        return ans;
    }
};
