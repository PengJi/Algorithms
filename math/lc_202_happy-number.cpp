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

class Solution {
public:
    // 计算每位数字的平方和
    int cal(int n) {
        int res = 0;

        while(n) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }

        return res;
    }

    // 快慢指针
    // 一定存在环，使用快慢指针找到环的入口
    bool isHappy(int n) {
        int fast = cal(n), slow = n;

        // 查找环的入口
        while(fast != slow) {
            fast = cal(cal(fast));
            slow = cal(slow);
        }

        return fast == 1;  // 环的入口是否为1
    }
};
