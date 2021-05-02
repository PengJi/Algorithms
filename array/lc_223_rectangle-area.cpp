/**
 * 223. 矩形面积
 * https://leetcode-cn.com/problems/rectangle-area/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/320/
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long x = min(C, G) + 0ll - max(A, E);
        long long y = min(D, H) + 0ll - max(B, F);
        return (C - A) * (D - B) - max(0ll, x) * max(0ll, y) + (G - E) * (H - F);
    }
};
