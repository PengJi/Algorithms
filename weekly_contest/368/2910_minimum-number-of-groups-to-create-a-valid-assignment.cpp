/**
 * 2910. 合法分组的最少组数
 * https://leetcode.cn/problems/minimum-number-of-groups-to-create-a-valid-assignment/description/
*/
class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            cnt[x]++;
        }
        int k = min_element(cnt.begin(), cnt.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->second;
        for (; ; k--) {
            int ans = 0;
            for (auto &[_, c] : cnt) {
                if (c / k < c % k) {
                    ans = 0;
                    break;
                }
                ans += (c + k) / (k + 1);
            }
            if (ans) {
                return ans;
            }
        }
    }
};
