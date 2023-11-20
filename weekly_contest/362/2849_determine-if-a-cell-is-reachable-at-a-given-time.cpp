/**
 * 2849. 判断能否在给定时间到达单元格
 * https://leetcode.cn/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/
*/
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy)
            return t != 1;

        return t >= max(abs(sx - fx), abs(sy - fy));
    }
};
