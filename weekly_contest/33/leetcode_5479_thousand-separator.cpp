/**
 * 5479. 千位分隔数
 * 给你一个整数 n，请你每隔三位添加点（即 "." 符号）作为千位分隔符，并将结果以字符串格式返回。
 * 
 * https://leetcode-cn.com/problems/thousand-separator/
 */

class Solution {
public:
    string thousandSeparator(int n) {
        string str = to_string(n);  // 转为字符串
        string ans;
        int count = 0;
        for(int i = str.size()-1; i >= 0; i--) {
            ans += str[i];
            count++;

            if(count % 3 == 0 && i != 0) {  // 每3位分隔
                ans += '.';
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
