typedef long long LL;

class Solution {
public:
    LL beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> h;
        h[0] = 1;

        int s = 0;
        LL ans = 0;
        for (int x : nums) {
            s ^= x;
            ans += h[s];
            ++h[s];
        }

        return ans;
    }
};
