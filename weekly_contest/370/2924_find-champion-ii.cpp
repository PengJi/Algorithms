/**
 * 2924. 找到冠军 II
 * https://leetcode.cn/problems/find-champion-ii/description/
*/
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> indeg(n, false);
        for (const auto &e : edges)
            indeg[e[1]] = true;

        int c = 0, r = -1;
        for (int i = 0; i < n; i++)
            if (!indeg[i]) {
                r = i;
                ++c;
            }

        if (c > 1)
            return -1;

        return r;
    }
};
