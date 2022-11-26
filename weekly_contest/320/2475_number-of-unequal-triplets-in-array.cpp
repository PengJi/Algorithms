class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> seen;

        for (int x : nums)
            seen[x]++;

        int l = 0, r = nums.size(), ans = 0;
        for (const auto &[_, v] : seen) {
            r -= v;
            ans += l * v * r;
            l += v;
        }

        return ans;
    }
};
