/**
 * 5705. 判断国际象棋棋盘中一个格子的颜色
 * https://leetcode-cn.com/problems/determine-color-of-a-chessboard-square/
 */

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto t : nums) {
            int a = t;
            string ss = to_string(a);
            reverse(ss.begin(), ss.end());
            mp[a - stoi(ss)]++;
        }

        int res = 0;
        const int MOD = 1e9+7;
        for(auto t : mp) {
            res = (res + (long long )t.second * (t.second-1)/2) % MOD;
        }

        return res;
    }
};
