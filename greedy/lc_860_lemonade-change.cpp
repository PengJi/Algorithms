/**
 * 860. 柠檬水找零
 * https://leetcode-cn.com/problems/lemonade-change/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/lemonade-change/solution/ning-meng-shui-zhao-ling-by-leetcode/
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5)
                five++;
            else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};

class Solution {
public:
    // 贪心算法
    // 两个变量分别记录5元和10元的数量
    // 收到5元，数量加一；
    // 收到10元，如果没有5元，则返回 false；
    // 收到20元，如果有10元，并且至少有一张5元，则 10+5；如果没有10元，则至少有3张5元，否则，返回false。
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for (auto& x : bills) {
            if (x == 5)
                fives++;
            else if (x == 10) {
                if (fives == 0)
                    return false;
                tens++;
                fives--;
            } else {
                if (tens >= 1 && fives >= 1) {
                    tens--;
                    fives--;
                } else if (tens == 0 && fives >= 3) {
                    fives -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};
