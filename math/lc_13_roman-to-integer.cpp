/**
 * 13. 罗马数字转整数
 * https://leetcode-cn.com/problems/roman-to-integer/
 */

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> T = { { 'I' , 1 },
                                       { 'V' , 5 },
                                       { 'X' , 10 },
                                       { 'L' , 50 },
                                       { 'C' , 100 },
                                       { 'D' , 500 },
                                       { 'M' , 1000 } };
                                       
       int sum = T[s.back()];
       for (int i = s.length() - 2; i >= 0; --i) {
           if (T[s[i]] < T[s[i + 1]]) {
               sum -= T[s[i]];
           } else {
               sum += T[s[i]];
           }
       }
       
       return sum;
    }
};


class Solution {
public:
    // 从后向前遍历
    int romanToInt(string s) {
        unordered_map<char, int> mp = { { 'I' , 1 },
                                    { 'V' , 5 },
                                    { 'X' , 10 },
                                    { 'L' , 50 },
                                    { 'C' , 100 },
                                    { 'D' , 500 },
                                    { 'M' , 1000 } };
        int len = s.size();
        int sum = mp[s[len-1]];
        for(int i = len-2; i >= 0; i--) {
            if(mp[s[i]] < mp[s[i+1]]) {
                sum -= mp[s[i]];
            } else {
                sum += mp[s[i]];
            }
        }

        return sum;    
    }
};
