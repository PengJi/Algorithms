/**
 * 547. 朋友圈
 * https://leetcode-cn.com/problems/friend-circles/
 */

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int len = M.size();
        vector<int> bossOf(len, 0);  // save the boss of user i
        // initially, i is the boss of himself
        for (int i = 0; i < len; i++)    
            bossOf[i] = i;
        // initially, every gang consists of one people
        int numOfGangs = len;  
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {   
                if (M[i][j] > 0) {
                    int master1 = findGangMaster(i, bossOf);
                    int master2 = findGangMaster(j, bossOf);
                    if (master1 != master2) {
                        // now merge two gangs, because of the friendship of i & j
                        bossOf[master2] = master1;
                        numOfGangs--;
                    }
                }
            }
        }
        return numOfGangs;
    }
    
    int findGangMaster(int x, vector<int>& bossOf) {
        return bossOf[x] == x ? x : findGangMaster(bossOf[x], bossOf);
    }
};
