/**
 * 2443. 反转之后的数字和
 * https://leetcode.cn/problems/sum-of-number-and-its-reverse/
*/
class Solution {
public:
    // 暴力解法，枚举
    bool sumOfNumberAndReverse(int num) {
        if(num == 0) return true;
        
        for(int i = 0; i < num; i++) {
            int x = i, t = 0;

            while(x) {
                t = t * 10 + x % 10;
                x /= 10;
            }

            if(i + t == num) return true;
        }

        return false;
    }
};
