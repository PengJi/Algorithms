class Solution {
public:
    static bool cmp(const pair<int,int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> odd, even;
        vector<pair<int, int> > o(1), e(1);
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            if(i % 2 == 0) {
                even[nums[i]]++;
            } else {
                odd[nums[i]]++;
            }
        }

        for(auto [k, v] : odd) {
            o.push_back(make_pair(k, v));
        }
        for(auto [k, v] : even) {
            e.push_back(make_pair(k, v));
        }

        sort(o.begin(), o.end(), cmp);
        sort(e.begin(), e.end(), cmp);

        if(o[0].first != e[0].first) {
            return len - o[0].second - e[0].second;
        } else {
            return len - max(o[0].second + e[1].second, o[1].second + e[0].second);
        }
    }
};
