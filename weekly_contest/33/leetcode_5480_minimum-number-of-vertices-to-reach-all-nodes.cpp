/**
 * 5480. 可以到达所有点的最少点数目
 * 给你一个 有向无环图 ， n 个节点编号为 0 到 n-1 ，以及一个边数组 edges ，
 * 其中 edges[i] = [fromi, toi] 表示一条从点  fromi 到点 toi 的有向边。
 * 找到最小的点集使得从这些点出发能到达图中所有点。题目保证解存在且唯一。
 * 
 * https://leetcode-cn.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
 */

class Solution {
public:
    // 统计所有入度为0的节点
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in_deg(n, 0);
        for(auto e : edges) {
            in_deg[e[1]]++;
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(in_deg[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};
