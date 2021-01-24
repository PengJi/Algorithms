/**
 * 5661. 替换隐藏数字得到的最晚时间
 * https://leetcode-cn.com/problems/latest-time-by-replacing-hidden-digits/
 */

class Solution {
public:
    string maximumTime(string time) {
        if(time[0] == '?') {
            if(time[1]=='?'){
                time[0] = '2';
                time[1] = '3';
            }
            else if(time[1] <= '3')
                time[0] = '2';
            else 
                time[0] = '1';
        } else if(time[1]=='?') {
            if(time[0] == '2')
                time[1] = '3';
            else 
                time[1] = '9';
        }

        if(time[3] == '?')
            time[3] = '5';
        if(time[4] == '?')
            time[4] = '9';

        return time;
    }
};