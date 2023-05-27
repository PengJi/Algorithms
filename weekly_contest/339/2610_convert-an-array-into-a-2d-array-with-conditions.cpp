class Solution {
public:
    // 哈希表。
    // 妙！
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int x : nums)
            ++seen[x];

        vector<vector<int>> ans;
        for (const auto &[k, v] : seen) {
            if (ans.size() < v)
                ans.resize(v);

            for (int i = 0; i < v; i++)
                ans[i].push_back(k);
        }

        return ans;
    }
};
