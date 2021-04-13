/**
 * 168. Excel表列名称
 * https://leetcode-cn.com/problems/excel-sheet-column-title/
 */

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/417085/
    string convertToTitle(int n) {
        int k = 1;
        for (long long p = 26; n > p; p *= 26) {
            n -= p;
            k ++ ;
        }

        n -- ;
        string res;
        while (k -- ) {
            res += n % 26 + 'A';
            n /= 26;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
