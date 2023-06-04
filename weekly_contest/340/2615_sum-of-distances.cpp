/**
 * 2615. 等值距离和
 * https://leetcode.cn/problems/sum-of-distances/
*/
typedef long long LL;

class Solution {
public:
    // 思维题
    vector<LL> distance(vector<int>& nums) {
        const int n = nums.size();

        unordered_map<int, vector<int>> p;
        for (int i = 0; i < n; i++)
            p[nums[i]].push_back(i);

        vector<LL> ans(n);
        for (const auto &[_, v] : p) {
            int m = v.size();

            LL sum = 0;
            for (int i = 1; i < m; i++)
                sum += v[i] - v[0];

            ans[v[0]] = sum;
            for (int i = 1; i < m; i++) {
                sum += (LL)(2 * i - m) * (v[i] - v[i - 1]);
                ans[v[i]] = sum;
            }
        }

        return ans;
    }
};
