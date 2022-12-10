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

class Solution {
public:
    // 相当于进制转换
    // 讲一个数 c 转换为其他进制都可采用下面的方法
    string convertToTitle(int c) {
        string res = "";
        int n = 0;

        while(c) {
            c--;
            n = c %  26;  // 求余数
            res += ('A' + n);  // 先求的个数，后面需要 reverse
            c /= 26;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
