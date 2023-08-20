/**
 * 2745. 构造最长的新字符串
 * https://leetcode.cn/problems/construct-the-longest-new-string/description/
*/

class Solution {
public:
    int longestString(int x, int y, int z) {
        if (abs(x - y) <= 1)
            return (x + y + z) * 2;

        return (2 * min(x, y) + 1 + z) * 2;
    }
};
