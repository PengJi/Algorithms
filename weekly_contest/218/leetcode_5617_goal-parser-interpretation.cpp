/**
 * 5617. 设计 Goal 解析器
 * https://leetcode-cn.com/problems/goal-parser-interpretation/
 */

class Solution {
public:
    string interpret(string command) {
        string ans;
        
        for(int i = 0; i < command.size();) {
            if(command[i] == 'G') {
                ans += "G";
                i++;
            } else if(command[i] == '(' && command[i+1] == ')') {
                ans += "o";
                i = i + 2;
            } else {
                ans += "al";
                i = i + 4;
            }
        }
        
        return ans;
    }
};
