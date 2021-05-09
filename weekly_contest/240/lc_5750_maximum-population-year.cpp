/**
 * 5750. 人口最多的年份
 * https://leetcode-cn.com/problems/maximum-population-year/
 */

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int res, cnt = 0;
        for(int i = 1950; i <= 2050; i++) {
            int c = 0;
            for(auto log : logs) {
                if(i >= log[0] && i < log[1]) c++;
            }

            if(c > cnt) res = i, cnt = s;
        }

        return res;
    }
};
