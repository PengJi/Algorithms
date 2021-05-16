/**
 * 5760. 构成交替字符串需要的最小交换次数
 * https://leetcode-cn.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
 */

class Solution {
public:
    int minSwaps(string s) {
        int len = s.size();
        string a(len, '0'), b(len, '0');
        for(int i = 0; i < len; i += 2) a[i] = '1';
        for(int i = 1; i < len; i += 2) b[i] = '1';
        int res = min(cnt(s, a), cnt(s, b));
        if(res == INT_MAX) return -1;
        return res;
    }

    int cnt(string s, string c) {
        int a = 0, b = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != c[i]) {
                if(s[i] == '0') a++;
                else b++;
            }
        }

        if(a != b) return INT_MAX;
        return a;
    }
};
