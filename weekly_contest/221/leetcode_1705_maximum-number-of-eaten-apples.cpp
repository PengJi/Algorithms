/**
 * 1705. 吃苹果的最大数目
 * https://leetcode-cn.com/problems/maximum-number-of-eaten-apples/
 */

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0;
        int n = apples.size();
        map<int, int> mp;
        for(int i = 0; i <= 100000; i++) {
            if(i < n) {
                mp[i + days[i]] += apples[i];
            }

            while(mp.size() > 0) {
                auto iter = mp.begin();
                if(iter->first <= i || iter->second <= 0) {
                    mp.erase(iter);
                } else {
                    break;
                }
            }

            if(mp.size() > 0) {
                mp.begin()->second -= 1;
                ans += 1;
            }
        }

        return ans;
    }
};
