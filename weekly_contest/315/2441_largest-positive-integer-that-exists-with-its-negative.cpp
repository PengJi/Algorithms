/**
 * 2441. 与对应负数同时存在的最大正整数
 * https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative/
*/
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = -1;
        unordered_set<int> st;
        for(auto x : nums) st.insert(x);
        for(auto x : nums) {
            if(x > 0 && st.count(-x) > 0) {
                if(x > res) res = x;
            }
        }

        return res;
    }
};
