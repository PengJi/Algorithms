/**
 * 2520. 统计能整除数字的位数
 * https://leetcode.cn/problems/count-the-digits-that-divide-a-number/description/
*/

class Solution {
public:
    int countDigits(int num) {
        int t = num, ans = 0;

        while (t) {
            if (num % (t % 10) == 0)
                ans++;

            t /= 10;
        }

        return ans;
    }
};
