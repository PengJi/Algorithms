/**
 * 461. 汉明距离
 * https://leetcode-cn.com/problems/hamming-distance/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/hamming-distance/solution/yi-ming-ju-chi-by-leetcode/
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;
        int distance = 0;
        while (tmp != 0) {
            distance += 1;
            // remove the rightmost bit of '1'
            tmp = tmp & (tmp - 1);
        }
        return distance;
    }
};
