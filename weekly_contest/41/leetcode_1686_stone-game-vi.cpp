/**
 * 1686. 石子游戏 VI
 * https://leetcode-cn.com/problems/stone-game-vi/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/stone-game-vi/solution/c-tan-xin-zheng-ming-by-spacex-1-xi8y/
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int, int>> mp; //记录价值和以及下标
        int n = aliceValues.size();

        for(int i = 0; i < n; i++) {
            int dis = aliceValues[i] + bobValues[i];
            mp.emplace_back(dis, i);
        }
        sort(mp.rbegin(), mp.rend()); //从大到小排序
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) {
                sum1 += aliceValues[mp[i].second];//偶数下标a来取
            } else {
                sum2 += bobValues[mp[i].second];  //奇数下标b来取
            }
        }

        if(sum1 == sum2) {
            return 0; //比较结果
        } else if(sum1 > sum2) {
            return 1;
        } else {
            return -1;
        }
    }
};
