/**
 * 2712. 使所有字符相等的最小成本
 * https://leetcode.cn/problems/minimum-cost-to-make-all-characters-equal/description/
*/

typedef long long LL;

class Solution {
public:
    LL work(string str, char c) {
        int n = str.size();
        LL res = 0;

        bool flag = false;
        for (int i = n - 1; i >= 0; -- i ) {
            if (str[i] != c && !flag)
                flag = true, res += i + 1;
            else if (str[i] == c && flag)
                flag = false, res += i + 1;
        }
        return res;
    }

    LL get(string str, char c) {
        int n = str.size();
        string s1 = str.substr(0, n / 2), s2 = str.substr(n / 2);
        reverse(s2.begin(), s2.end());
        return work(s1, c) + work(s2, c);
    }

    long long minimumCost(string s) {
        return min(get(s, '0'), get(s, '1'));
    }
};
