/**
 * 2930. 重新排列后包含指定子字符串的字符串数目
 * https://leetcode.cn/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/description/
*/
#define LL long long

const int mod = 1000000007;

class Solution {
private:
    LL power(int x, int y) {
        LL tot = 1, p = x;
        for (; y; y >>= 1) {
            if (y & 1) tot = tot * p % mod;
            p = p * p % mod;
        }

        return tot;
    }

public:
    int stringCount(int n) {
        return ((power(26, n) - 3 * power(25, n) - n * power(25, n - 1) + 
            3 * power(24, n) + 2 * n * power(24, n - 1) - power(23, n) -
            n * power(23, n - 1)) % mod + mod) % mod;
    }
};
