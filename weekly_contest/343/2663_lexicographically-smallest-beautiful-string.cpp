/**
 * 2663. 字典序最小的美丽字符串
 * https://leetcode.cn/problems/lexicographically-smallest-beautiful-string/
*/
class Solution {
public:
    char get_next(char c, int k,  char c1, char c2) {
        while (c < 'a' + k && (c == c1 || c == c2))
            ++c;

        if (c >= 'a' + k)
            return 0;

        return c;
    }

    string smallestBeautifulString(string s, int k) {
        const int n = s.size();

        int p = n - 1;
        for (int i = 1; i < n; i++)
            if (s[i] == s[i - 1] || (i > 1 && s[i] == s[i - 2])) {
                p = i;

                break;
            }

        while (p >= 0 && 
            get_next(s[p] + 1, k, p > 0 ? s[p - 1] : 0, p > 1 ? s[p - 2] : 0) == 0
        )
            --p;

        if (p == -1)
            return "";

        s[p] = get_next(s[p] + 1, k, p > 0 ? s[p - 1] : 0, p > 1 ? s[p - 2] : 0);
        for (int i = p + 1; i < n; i++)
            s[i] = get_next('a', k, s[i - 1], i > 1 ? s[i - 2] : 0);

        return s;
    }
};
