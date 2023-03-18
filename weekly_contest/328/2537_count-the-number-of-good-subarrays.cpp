#define LL long long

class Solution {
public:
    // 双指针
    LL countGood(vector<int>& nums, int k) {
        const int n = nums.size();

        unordered_map<int, int> seen;
        int tot = 0;
        LL res = 0;

        for (int l = 0, r = 0; r < n; r++) {
            tot += seen[nums[r]];
            ++seen[nums[r]];

            while (l <= r && tot >= k) {
                --seen[nums[l]];
                tot -= seen[nums[l]];
                l++;
            }

            res += l;
        }

        return res;
    }
};
