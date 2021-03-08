/**
 * 5681. 判断一个数字是否可以表示成三的幂的和
 * https://leetcode-cn.com/problems/check-if-number-is-a-sum-of-powers-of-three/
 */

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n != 0) {
            if(n % 3 == 2) return false;
            n = n/3;
        }

        return true;
    }
};
