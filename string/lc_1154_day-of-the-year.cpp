/**
 * 1154. 一年中的第几天
 * https://leetcode.cn/problems/day-of-the-year/description/
 */

class Solution {
public:
    int dayOfYear(string date) {
        int res = 0;
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = 0, month = 0, day = 0;
        int tmp;

        for (int i = 0; i < 4; i++) {
            tmp = date[i] - '0';
            year = year * 10 + tmp;
        }
        for (int i = 5; i < 7; i++) {
            tmp = date[i] - '0';
            month = month * 10 + tmp;
        }
        for (int i = 8; i < 10; i++) {
            tmp = date[i] - '0';
            day = day * 10 + tmp;
        }

        for (int i = 0; i < month - 1; i++) res += days[i];
        res += day;

        // 闰年的判定方法为：year 是 400 的倍数，或者 year 是 4 的倍数且不是 100 的倍数。
        if (month > 2 && (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)) res++;

        return res;
    }
};
