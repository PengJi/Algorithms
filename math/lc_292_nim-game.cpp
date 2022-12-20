/**
 * 292. Nim 游戏
 * https://leetcode-cn.com/problems/nim-game/
 */

class Solution {
public:
    bool canWinNim(int n) {
        return n & 3;
    }
};

class Solution {
public:
    // 如果 n 能被 4 整除，假设每次取 x 枚石子，则对手可以取 4-x 枚石子，最后一枚石子一定会被对手取走，必败。
    // 如果 n 不能被 4 整除，第一次取走 n%4 枚石子，剩下的石子数是 4 的倍数，则按照上一种情况，必胜。 
    bool canWinNim(int n) {
        return n & 3;  // n % 4 == n & 3
    }
};
