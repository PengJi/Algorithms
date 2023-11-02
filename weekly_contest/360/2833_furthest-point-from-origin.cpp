/**
 * 2833. 距离原点最远的点
 * https://leetcode.cn/problems/furthest-point-from-origin/description/
*/
class Solution {
public:
    // 贪心
    int furthestDistanceFromOrigin(string moves) {
        int res = 0, cnt = 0;

        for (char c : moves) {
            if (c == 'L') --res;
            else if (c == 'R') ++res;
            else ++cnt;
        }

        return max(abs(res - cnt), abs(res + cnt));
    }
};
