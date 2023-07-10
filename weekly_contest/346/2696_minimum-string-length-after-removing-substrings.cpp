/**
 * 2696. 删除子串后的字符串最小长度
 * https://leetcode.cn/problems/minimum-string-length-after-removing-substrings/description/
*/

class Solution {
public:
    inline bool judge(char a, char b) {
        return (a == 'A' && b == 'B') || (a == 'C' && b == 'D');
    }

    // 栈
    int minLength(string s) {
        const int n = s.size();

        int i =  1, j = 1;
        while(j < n) {
            if(i > 0 && judge(s[i-1], s[j])) --i;
            else s[i++] = s[j];

            ++j;
        }

        return i;
    }
};
