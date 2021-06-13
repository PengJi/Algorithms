/**
 * 5785. 合并若干三元组以形成目标三元组
 * https://leetcode-cn.com/problems/merge-triplets-to-form-target-triplet/
 */

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = 0, y = 0, z = 0;
        for(auto t: triplets) {
            if(t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;
            x = max(x, t[0]);
            y = max(y, t[1]);
            z = max(z, t[2]);
        }

        return x == target[0] && y == target[1] && z == target[2];
    }
};
