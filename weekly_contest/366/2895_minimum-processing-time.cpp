/**
 * 2895. 最小处理时间
 * https://leetcode.cn/problems/minimum-processing-time/description/
*/
class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        const int n = processorTime.size();
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());

        int ans = 0;
        for (int i = 0, j = 4 * n - 1; j >= 0; i++, j--)
            ans = max(ans, processorTime[i / 4] + tasks[j]);

        return ans;
    }
};
