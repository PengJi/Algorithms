/**
 * 2798. 满足目标工作时长的员工数目
 * https://leetcode.cn/problems/number-of-employees-who-met-the-target/description/
*/
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;

        for (int x : hours)
            if (x >= target)
                ++ans;

        return ans;
    }
};
