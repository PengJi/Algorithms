class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto n : nums) mp[n]++;
        vector<int> res(2);
        for(auto [k, v] : mp) res[0] += v / 2;
        res[1] = nums.size() - res[0] * 2;
        return res;
    }
};
