/**
 * 2651. 计算列车到站时间
 * https://leetcode.cn/problems/calculate-delayed-arrival-time/
*/
class Solution {
public:
    // 模拟
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};
