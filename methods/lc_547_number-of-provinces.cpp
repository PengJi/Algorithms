/**
 * 547. 省份数量
 * https://leetcode-cn.com/problems/number-of-provinces/
 */

class Solution {
public:
    // https://leetcode.com/problems/friend-circles/discuss/101354/C%2B%2B-Clean-Code-DFSorUnionFind
    int findCircleNum(vector<vector<int>>& M) {
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

    // 并查集
    vector<int> p;

    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = n;
        for(int i = 0; i < n; i++) p.push_back(i);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] && find(i) != find(j)) {
                    p[find(i)] = find(j);
                    res--;
                }
            }
        }

        return res;
    }
};
