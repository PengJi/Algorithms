class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int n = nums.size();
        for(auto q : queries) {
            int d = 0, s = 0;
            while(d < n && s+nums[d] <= q) {
                s += nums[d++];
            }
            res.push_back(d);
        }

        return res;
    }
};
