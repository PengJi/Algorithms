/**
 * 5194. 得到目标值的最少行动次数
 * https://leetcode-cn.com/problems/minimum-moves-to-reach-target-score/
 */

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res = 0;
        while(target != 1) {
            if(maxDoubles == 0) {
                res += (target - 1);
                break;
            }
            if(target % 2 == 0) {
                target /= 2;
                res++;
                maxDoubles--;
            } else {
                target /= 2;
                res += 2;
                maxDoubles--;
            }
        }
        return res;
    }
};
