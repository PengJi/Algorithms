/**
 * 202. 快乐数
 * https://leetcode-cn.com/problems/happy-number/
 */

class Solution {
public:
    // 快慢指针
    // https://leetcode-cn.com/problems/happy-number/solution/shi-yong-kuai-man-zhi-zhen-si-xiang-zhao-chu-xun-h/
    bool isHappy(int n) {
        int slow = n, fast = n;

        do {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        } while(slow != fast);

        return slow == 1;
    }

    int bitSquareSum(int n) {
        int sum = 0;
        while(n > 0) {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }

        return sum;
    }
};
