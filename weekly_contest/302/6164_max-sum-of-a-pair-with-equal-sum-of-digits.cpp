class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int res = -1;
        unordered_map<int, int> mp;
        for(auto n : nums) {
            int s = 0, cur = n;
            while(cur > 0) s += cur % 10, cur /= 10;
            if(mp.count(s)) res = max(res, n + mp[s]);
            mp[s] = max(mp[s], n);
        }

        return res;
    }
};
