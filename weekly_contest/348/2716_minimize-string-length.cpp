/**
 * 2716. 最小化字符串长度
 * https://leetcode.cn/problems/minimize-string-length/description/
*/

class Solution {
public:
    int minimizedStringLength(string s) {
        int seen = 0, ans = 0;

        for (char c : s) {
            if (!((seen >> (c - 'a')) & 1))
                ++ans;

            seen |= 1 << (c - 'a');
        }

        return ans;
    }
};
