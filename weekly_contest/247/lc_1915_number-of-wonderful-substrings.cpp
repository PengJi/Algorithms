/**
 * 1915. 最美子字符串的数目
 * https://leetcode-cn.com/problems/number-of-wonderful-substrings/
 */

typedef long long LL;

const int N = 100010;

int s[N][10];
int cnt[1024];

class Solution {
public:
    long long wonderfulSubstrings(string str) {
        int n = str.size();
        LL res = 0;
        memset(cnt, 0, sizeof cnt);
        cnt[0] ++ ;
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 0; j < 10; j ++ )
                if (str[i - 1] - 'a' == j) s[i][j] = s[i - 1][j] + 1;
                else s[i][j] = s[i - 1][j];
            int state = 0;
            for (int j = 0; j < 10; j ++ )
                state = state * 2 + s[i][j] % 2;
            res += cnt[state];
            for (int j = 0; j < 10; j ++ )
                res += cnt[state ^ (1 << j)];
            cnt[state] ++ ;
        }
        return res;
    }
};
