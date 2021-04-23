/**
 * 171. Excel表列序号
 * https://leetcode-cn.com/problems/excel-sheet-column-number/
 */

class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long res = 0;
        for(auto c : columnTitle) {
            res = res * 26 + c - 'A' + 1;
        }

        return res;
    }
};
