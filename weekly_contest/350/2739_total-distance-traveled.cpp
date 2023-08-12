/**
 * 2739. 总行驶距离
 * https://leetcode.cn/problems/total-distance-traveled/description/
*/

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int r = mainTank / 4 - (mainTank % 4 == 0);

        return 10 * (mainTank + min(r, additionalTank));
    }
};
