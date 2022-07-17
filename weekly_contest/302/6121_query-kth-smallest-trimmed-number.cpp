class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<pair<string, int>> strs(n);
        for(int i = 0; i < n; i++) strs[i] = {nums[i], i};
        vector<int> res;
        for(auto& q : queries) {
            int k = q[0], trim = q[1];
            sort(strs.begin(), strs.end(), [&](pair<string, int>& a, pair<string, int>& b) {
                for(int i = a.first.size() - trim; i < a.first.size(); i++) {
                    if(a.first[i] < b.first[i]) return true;
                    else if(a.first[i] > b.first[i]) return false;
                }
                return a.second < b.second;
            });
            res.push_back(strs[k-1].second);
        }

        return res;
    }
};
