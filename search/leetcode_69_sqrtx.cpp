/**
 * 69. x 的平方根
 * 实现 int sqrt(int x) 函数。
 * 
 * https://leetcode-cn.com/problems/sqrtx/
 */

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x, ans = -1;
        int mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if((long long)mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};