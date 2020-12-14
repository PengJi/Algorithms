/**
 * 1689. 十-二进制数的最少数目
 * https://leetcode-cn.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
 */

class Solution {
public:
    int minPartitions(string n) {
        int flag = n[0] - '0';
        for(int i = 0; i < n.size(); i++) {
            if(flag < (n[i] - '0')) {
                flag = n[i] - '0';
            }
        }

        return flag;
    }
};
