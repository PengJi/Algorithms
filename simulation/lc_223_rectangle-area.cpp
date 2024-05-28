/**
 * 223. 矩形面积
 * https://leetcode-cn.com/problems/rectangle-area/
 */

class Solution {
public:
    // 两个矩形并集的面积 = 两个矩形的总面积 - 两个矩形交集的面积。
    // 两个矩形如果有交集，那么交集一定是矩形，剩下的问题是求出交集的长和宽。
    // 求交集的长和宽是一个一维问题，即在数轴上给出线段 [A,B] 和 [C,D]，求它们交集的长度。
    // 其交集的长度：L=min(B,D)−max(A,C)，如果 L<0𝐿<0，说明两个线段不重合。
    // https://www.acwing.com/solution/content/320/
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long x = min(C, G) + 0ll - max(A, E);
        long long y = min(D, H) + 0ll - max(B, F);
        return (C - A) * (D - B) - max(0ll, x) * max(0ll, y) + (G - E) * (H - F);
    }
};
